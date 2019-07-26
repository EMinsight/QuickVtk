#include "quickVtkThreadedImageAlgorithm.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::Symbol::AbstractClass<ThreadedImageAlgorithm> ThreadedImageAlgorithm::Register;

        ThreadedImageAlgorithm::ThreadedImageAlgorithm(vtkSmartPointer<vtkThreadedImageAlgorithm> vtkObject) : ImageAlgorithm(vtkObject) {
        }
    }
}
