#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H
#include <iostream>
#include <array>

class TcpConnection
{
    public:
        std::array<char, 100> readNext();
        void writeNext(const std::array<char, 100>& blob);
};
#endif