#pragma once

#include "quickQmlRegister.hpp"

#include <QObject>

namespace quick {

    namespace App {

        class Menu : public QObject {
            Q_OBJECT
            Q_PROPERTY(QStringList examples READ getExamples CONSTANT);
        private:
            static Menu* instance;
            QStringList m_examples;
            static Qml::Register::Type<Menu> Register;
            auto init() -> void;
            Menu();
        public:
            static auto GetInstance() -> Menu*;
            auto getExamples() -> QStringList;
        public slots:
            void OnFileOpen();
            void OnFindFind();

            void OnCodeRun();

            void OnViewIncreaseFontSize();
            void OnViewDecreaseFontSize();
            void OnViewResetFontSize();
            void OnViewToggleEditor();

            void OnHelpVisitOnGitHub();
            void OnHelpSendFeedback();
            void OnHelpExample(const QString&);
        };
    }
}
