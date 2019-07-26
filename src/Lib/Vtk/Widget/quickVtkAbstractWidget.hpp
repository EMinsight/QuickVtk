#pragma once

#include "quickQmlRegister.hpp"
#include "quickVtkObject.hpp"

#include <vtkSmartPointer.h>
#include <vtkAbstractWidget.h>

namespace quick {

    namespace Vtk {

        class AbstractWidget : public Object {
            Q_OBJECT
            Q_PROPERTY(bool enabled READ getEnabled WRITE setEnabled NOTIFY enabledChanged);
        private:
            static Qml::Register::Symbol::AbstractClass<AbstractWidget> Register;
            bool m_enabled;
            vtkSmartPointer<vtkAbstractWidget> m_vtkObject = nullptr;
        public:
            AbstractWidget() = delete;
            AbstractWidget(vtkSmartPointer<vtkAbstractWidget>);
            auto setEnabled(bool) -> void;
            auto getEnabled() -> bool;
            auto getVtkObject() -> vtkSmartPointer<vtkAbstractWidget>;
        signals:
            void enabledChanged();
        };
    }
}
