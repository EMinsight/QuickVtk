#pragma once

#include "quickQmlRegister.hpp"

#include <QColor>
#include <QObject>

#include <vtkSmartPointer.h>
#include <vtkProperty2D.h>
#include <vtkActor2D.h>

namespace quick {

    namespace Vtk {

        class Actor2D;

        class Property2D : public QObject {
            Q_OBJECT
            Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged);
            Q_PROPERTY(double opacity READ getOpacity WRITE setOpacity NOTIFY opacityChanged);
        private:
            static Qml::Register::Symbol::UncreatableClass<Property2D> Register;
            QColor m_color;
            quick::Vtk::Actor2D* m_actor2D;
            vtkSmartPointer<vtkActor2D> m_vtkActor2D;
        private:
            void update();
        public:
            Property2D() = delete;
            Property2D(Actor2D*);
            auto setColor(QColor) -> void;
            auto getColor() -> QColor;
            auto setOpacity(double) -> void;
            auto getOpacity() -> double;
        signals:
            void colorChanged();
            void opacityChanged();
        };
    }
}
