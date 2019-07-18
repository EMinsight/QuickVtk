#pragma once

#include "quickVtkMapper2D.hpp"

#include <vtkImageMapper.h>

namespace quick {

    namespace Vtk {

        class ImageMapper : public Mapper2D {
            Q_OBJECT
            Q_PROPERTY(float colorWindow READ getColorWindow WRITE setColorWindow NOTIFY colorWindowChanged);
            Q_PROPERTY(float colorLevel READ getColorLevel WRITE setColorLevel NOTIFY colorLevelChanged);
            Q_PROPERTY(float colorShift READ getColorShift NOTIFY colorShiftChanged);
            Q_PROPERTY(float colorScale READ getColorScale NOTIFY colorScaleChanged);
        private:
            static Qml::Register::Symbol::Class<ImageMapper> Register;
            vtkSmartPointer<vtkImageMapper> m_vtkObject;
        public:
            ImageMapper();
            auto setColorWindow(float) -> void;
            auto getColorWindow() -> float;
            auto setColorLevel(float) -> void;
            auto getColorLevel() -> float;
            auto getColorShift() -> float;
            auto getColorScale() -> float;
        signals:
            void colorWindowChanged();
            void colorLevelChanged();
            void colorShiftChanged();
            void colorScaleChanged();
        };
    }
}
