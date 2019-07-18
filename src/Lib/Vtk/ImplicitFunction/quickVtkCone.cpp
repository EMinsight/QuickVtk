#include "quickVtkCone.hpp"

namespace quick {

    namespace Vtk {
        Qml::Register::Symbol::Class<Cone> Cone::Register;

        Cone::Cone() : ImplicitFunction(vtkSmartPointer<vtkCone>::New()) {
            this->m_vtkObject = vtkCone::SafeDownCast(ImplicitFunction::getVtkObject());
        }

        auto Cone::setAngle(float angle) -> void {
            this->m_vtkObject->SetAngle(angle);
            emit this->angleChanged();
        }

        auto Cone::getAngle() -> float {
            return this->m_vtkObject->GetAngle();
        }
    }
}
