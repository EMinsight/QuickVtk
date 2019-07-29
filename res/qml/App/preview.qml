import QtQuick 2.6

import Lib 1.0 as Lib

Rectangle {
    id: root;

    property string tabTitle: "Preview"

    property var previousObject: undefined;

    clip: true;

    color: "#181A1F"

    Item {
        id: container;

        anchors.fill: parent;
    }

    Rectangle {
        color: "#000"
        border.color: "#6E7582";
        width: 30;
        height: 22;
        anchors.right: parent.right;
        anchors.top: parent.top;
        anchors.margins: 4;
        radius: 4;
        opacity: ma.containsMouse ? 1 : 0.3;

        visible: Controllers.expanded;

        Lib.Icon {
            anchors.centerIn: parent;

            icon: icons.fa_navicon;
            color: ma.containsMouse ? "#fff" : "#9DA5B4";
        }

        MouseArea {
            id: ma;
            anchors.fill: parent;
            hoverEnabled: true;
            onClicked: Controllers.expanded = false;
        }
    }

    function compile() {
        var qmlObject = undefined;
        Controllers.editor.errors.clear();

        try {
            qmlObject = Qt.createQmlObject(Controllers.editor.getText(), container, "root");

            if (previousObject) {
                previousObject.destroy();
            }

            previousObject = qmlObject;
        }
        catch (exc) {
            var errors = exc.qmlErrors;

            for (var i = 0; i < errors.length; i++) {
                var error = errors[i];

                Controllers.editor.errors.add(error.lineNumber, error.columnNumber, error.message);
            }

            Controllers.editor.errors.update();
        }
    }

    Connections {
        target: Controllers.editor;
        onCompile: root.compile();
    }
}
