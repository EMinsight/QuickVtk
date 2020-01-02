import QtQuick 2.12

import Lib 1.0 as Lib

Rectangle {

  color: "#21252B"
  visible: !App.console.collapsed;

  Rectangle {
    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.top: parent.top;

    height: 1;
    color: "#181A1F";
  }

  Item {
    id: header;

    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.top: parent.top;

    height: label_type.height + 8;

    Lib.Label {
      id: label_type;

      anchors.verticalCenter: parent.verticalCenter;
      anchors.left: parent.left;
      leftPadding: 4;
      rightPadding: 4;

      text: "Type"
    }

    Lib.Label {
      id: label_time;

      anchors.verticalCenter: parent.verticalCenter;
      anchors.right: parent.right;
      rightPadding: 4;

      text: "Time"
    }

    Lib.Label {
      anchors.verticalCenter: parent.verticalCenter;
      anchors.left: label_type.right;
      anchors.right: label_time.left;

      text: "Description"
    }
  }

  Lib.List {
    anchors.top: header.bottom;
    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.bottom: footer.top;

    model: App.console.items;

    delegate: Item {

      anchors.left: parent.left;
      anchors.right: parent.right;
      height: label.height + 4;

      //color: index % 2 ? "#1a1c22" : "#181A1F";

      Lib.Icon {
        id: ic;
        icon: modelData.type == 0 ? icons.fa_info_circle : modelData.type > 1 ? icons.fa_exclamation_triangle : "";
        color: modelData.type == 2 ? "#ffff00" : modelData.type == 3 ? "#ff0000" : "#777";
        width: label_type.width;
        font.pointSize: 9;
        anchors.verticalCenter: parent.verticalCenter;
        horizontalAlignment: Text.AlignHCenter
      }

      Lib.Label {
        id: label;
        text: modelData.message;
        anchors.verticalCenter: parent.verticalCenter;
        anchors.left: ic.right;
        anchors.right: time.left;
      }

      Lib.Label {
        id: time;
        text: modelData.time;
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter;
        rightPadding: 4;
      }
    }
  }

  Item {
    id: footer;

    anchors.left: parent.left;
    anchors.right: parent.right;
    anchors.bottom: parent.bottom;

    height: 30;

    Rectangle {
      anchors.left: parent.left;
      anchors.right: parent.right;
      anchors.top: parent.top;

      height: 1;
      color: "#181A1F";
    }

    Lib.Button {
      id: btn_clear;

      anchors.verticalCenter: parent.verticalCenter;
      anchors.right: parent.right;
      anchors.rightMargin: 8;

      frameless: true;
      icon: icons.fa_trash;
      onClicked: App.console.clear();
    }
  }
}
