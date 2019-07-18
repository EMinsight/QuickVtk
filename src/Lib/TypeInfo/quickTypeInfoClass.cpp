#include "quickTypeInfoClass.hpp"
#include "quickTypeInfoProperty.hpp"
#include "quickTypeInfoMethod.hpp"

namespace quick {

    namespace TypeInfo {

        Class::Class() {
        }

        auto Class::setAbstract(bool abstract) -> void {
            this->m_abstract = abstract;
        }

        auto Class::isAbstract() -> bool {
            return this->m_abstract;
        }

        auto Class::setBase(const QString& base) -> void {
            this->m_base = base;
        }

        auto Class::getBase() -> QString {
            return this->m_base;
        }

        auto Class::getPropertyList() -> QQmlListProperty<Property> {
            return QQmlListProperty<Property>(this, this->m_properties);
        }

        auto Class::getMethodList() -> QQmlListProperty<Method> {
            return QQmlListProperty<Method>(this, this->m_methods);
        }

        auto Class::addProperty(QMetaProperty metaProperty) -> void {
            auto property = Property::Create(metaProperty);

            if (property) {
                this->m_properties.append(property);
            }
        }

        auto Class::addMethod(QMetaMethod metaMethod) -> void {
            auto method = Method::Create(metaMethod);

            if (method) {
                this->m_methods.append(method);
            }
        }
    }
}
