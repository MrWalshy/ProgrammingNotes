#ifndef OBJECT_H
#define OBJECT_H
#include <string>

class Object
{
    public:
        virtual std::string toString() = 0;
        virtual ~Object() = default;
        Object() = default;

        Object(const Object&) = delete;
        Object& operator=(const Object&) = delete;
        Object(Object&&) = delete;
        Object& operator=(Object&&) = delete;
};
#endif