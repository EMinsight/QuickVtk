#include "quickVtkSmartVolumeMapper.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::Symbol::Class<SmartVolumeMapper> SmartVolumeMapper::Register;

        SmartVolumeMapper::SmartVolumeMapper() : VolumeMapper(vtkSmartPointer<vtkSmartVolumeMapper>::New()) {
            this->m_vtkObject = vtkSmartVolumeMapper::SafeDownCast(this->Algorithm::getVtkObject());
        }

        auto SmartVolumeMapper::setFinalColorWindow(float finalColorWindow) -> void {
            this->m_vtkObject->SetFinalColorWindow(finalColorWindow);
            emit this->finalColorWindowChanged();
            this->update();
        }

        auto SmartVolumeMapper::getFinalColorWindow() -> float {
            return this->m_vtkObject->GetFinalColorWindow();
        }

        auto SmartVolumeMapper::setFinalColorLevel(float finalColorLevel) -> void {
            this->m_vtkObject->SetFinalColorLevel(finalColorLevel);
            emit this->finalColorLevelChanged();
            this->update();
        }

        auto SmartVolumeMapper::getFinalColorLevel() -> float {
            return this->m_vtkObject->GetFinalColorLevel();
        }
    }
}
