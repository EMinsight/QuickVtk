#include "quickVtkTextureMapToCylinder.hpp"

namespace quick {

    namespace Vtk {

        Qml::Register::Symbol::Class<TextureMapToCylinder> TextureMapToCylinder::Register;

        TextureMapToCylinder::TextureMapToCylinder() : DataSetAlgorithm(vtkSmartPointer<vtkTextureMapToCylinder>::New()) {
            this->m_vtkObject = vtkTextureMapToCylinder::SafeDownCast(this->getVtkObject());
        }
    }
}
