#include "TcpConnection.h"

std::array<char, 100> TcpConnection::readNext()
{
    std::cout << "Read data from TCP connection" << std::endl;
    return std::array<char, 100>();
}

void TcpConnection::writeNext(const std::array<char, 100>& blob)
{
    std::cout << "Data written to TCP connection" << std::endl;
}