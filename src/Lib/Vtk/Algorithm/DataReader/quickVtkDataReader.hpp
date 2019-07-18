#pragma once

#include "quickVtkAlgorithm.hpp"

#include <vtkDataReader.h>

namespace quick {

    namespace Vtk {

        class DataReader : public Algorithm {
            Q_OBJECT
            Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged);
        private:
            static Qml::Register::Symbol::AbstractClass<DataReader> Register;
            vtkSmartPointer<vtkDataReader> m_vtkObject;
        public:
            DataReader(vtkSmartPointer<vtkDataReader>);
            auto setFileName(const QString&) -> void;
            auto getFileName() -> QString;
        signals:
            void fileNameChanged();
        };
    }
}
