#pragma once

#include <QString>
#include <QThreadStorage>

namespace quick {

    namespace App {

        class Instance {
        private:
            QString resourceDir;
        private:
            static Instance* instance;
            QThreadStorage<bool> m_messageHandled;
            Instance();
            auto init() -> void;
            auto AddFontDir(const QString&) -> void;
            static auto HandleMessage(QtMsgType, const QMessageLogContext&, const QString&) -> void;
        public:
            static auto GetResourceDir() -> QString;
            static auto Execute(int, char**) -> int;
        };
    }
}
