#ifndef CONNECTION_H
#define CONNECTION_H
#include <array>
#include "TcpConnection.h"

template<typename Object, typename Connection>
Object readObjectFromConnection(Connection& con)
{
    std::array<char, 100> data = con.readNext();
    return Object::deserialize(data);
}

template<typename Object>
Object readObjectFromConnection(TcpConnection& con)
{
    std::array<char, 100> data = con.readNext();
    return Object::deserialize(data);
}
#endif