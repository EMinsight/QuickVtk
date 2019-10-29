---
layout: example
nav: examples
title: TriangleFilter
category: Vtk
---
{% highlight qml %}

import QtQuick 2.6

import Vtk 1.0 as Vtk
import Math 1.0 as Math
import Utils 1.0 as Utils

Item {
    id: root;

    anchors.fill: parent;

    Vtk.Viewer {
        anchors.fill: parent;

        mouseEnabled: true;

        Vtk.Actor {
            Vtk.PolyDataMapper {
                Vtk.TriangleFilter {
                    id: filter;

                    Vtk.STLReader {
                        fileName: SampleData.meshes.suzanneSTL;
                    }
                }
            }
        }
    }

    Utils.View {
        title: "TriangleFilter"

        Utils.CheckBox {
            from: filter; bind: "passVerts";
        }

        Utils.CheckBox {
            from: filter; bind: "passLines";
        }
    }
}

{% endhighlight %}
