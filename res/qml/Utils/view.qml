import QtQuick 2.6

import Utils 1.0 as Utils
import Lib 1.0 as Lib

Item {
    id: root;

    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.top: parent.top;
    anchors.margins: 8;

    height: column.height;

    default property alias content: contentColumn.children;
    property bool expanded: true;
    property alias title: label.text;

    Column {
        id: column;

        anchors.left: parent.left;
        anchors.right: parent.right;

        anchors.leftMargin: 8;
        anchors.rightMargin: 8;

        topPadding: 4;
        bottomPadding: 4;

        spacing: 2;

        Item {
            anchors.left: parent.left;
            anchors.right: parent.right;

            height: label.height;

            Lib.Icon {
                id: icon;

                anchors.left: parent.left;
                anchors.verticalCenter: parent.verticalCenter;
                width: parent.height;
                icon: root.expanded ? icons.fa_caret_down : icons.fa_caret_right;
                color: ma.containsMouse ? "#fff" : "#9DA5B4";
            }

            Utils.Label {
                id: label;

                anchors.left: icon.right;
                anchors.leftMargin: 8;

                text: "Properties"
                color: "#fff"
                font.bold: true;
            }

            MouseArea {
                id: ma;

                anchors.fill: parent;
                onClicked: root.expanded = !root.expanded;
                hoverEnabled: true;
            }
        }

        Column {
            id: contentColumn;

            visible: root.expanded;

            anchors.left: parent.left;
            anchors.right: parent.right;

            spacing: 8;
        }
    }

    Component.onCompleted:  {

      console.log("utilsView: " + utilsView);
      root.parent = utilsView;
    }
}
