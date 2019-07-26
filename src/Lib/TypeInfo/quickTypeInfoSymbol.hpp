#pragma once

#include "quickQmlRegister.hpp"

#include <QMetaObject>
#include <QObject>
#include <QColor>

namespace quick {

    namespace TypeInfo {

        class Symbol : public QObject {
            Q_OBJECT
            Q_PROPERTY(QColor color READ getColor CONSTANT);
            Q_PROPERTY(QString name READ getName CONSTANT);
            Q_PROPERTY(QString type READ getType CONSTANT);
            Q_PROPERTY(QString prefix READ getPrefix CONSTANT);
        private:
            struct Get {
                static auto ClassName(QMetaObject) -> QString;
                static auto ClassPrefix(QMetaObject) -> QString;
                static auto EnumName(QMetaEnum) -> QString;
                static auto EnumPrefix(QMetaEnum) -> QString;
                static auto BaseString(QMetaObject) -> QString;
            };
        private:
            QColor m_color;
            QString m_type;
            QString m_name;
            QString m_prefix;
        private:
            static auto GetEnums() -> QStringList&;
        public:
            static Qml::Register::Type<Symbol> Register;
            static auto MakeEnum(QMetaEnum) -> void;
            static auto MakeClass(QMetaObject) -> void;
            static auto MakeAbstractClass(QMetaObject) -> void;
            auto operator < (const Symbol&) -> const bool;
            auto getColor() -> QColor;
            auto getType() -> QString;
            auto getName() -> QString;
            auto getPrefix() -> QString;
            auto matches(const QString&) -> bool;
        };
    }
}
