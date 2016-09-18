//
// Created by Maxim Raukhvarger on 18.09.16.
//

#ifndef CPP_PROPS_PROPERTIES_H
#define CPP_PROPS_PROPERTIES_H

#include <iostream>

using namespace std;

namespace Properies {

    class PropertyAccessException {
    };

    enum PropertyType {
        ReadOnly,
        ReadWrite
    };

    template<class T, PropertyType propertyType = ReadOnly>
    class Property {

        T value;

        function<void(const T &)> on_read;

        function<void(const T &)> on_write;

        void write(const T &value) {
            if (propertyType != ReadOnly) {
                this->value = value;
                on_write(value);
            }
            else
                throw new PropertyAccessException();
        }


    public:

        Property() {
            value = T();
        }

        Property(const T &value,
                 function<void(const T &)> on_read = nullptr,
                 function<void(const T &)> on_write = nullptr) {
            this->value = value;
            setOnRead(on_read);
            setOnWrite(on_write);
        }

        const operator T() {
            on_read(value);
            return value;
        }

        T &operator=(const T &value) {
            write(value);
            return this->value;
        }

        const function<void(const T &)> &getOnRead() const {
            return on_read;
        }

        void setOnRead(const function<void(const T &)> &on_read) {
            this->on_read = on_read;
        }

        const function<void(const T &)> &getOnWrite() const {
            return on_write;
        }

        void setOnWrite(const function<void(const T &)> &on_write) {
            this->on_write = on_write;
        }
    };
}

#endif //CPP_PROPS_PROPERTIES_H
