#include "connection.h"
#include "TcpConnection.h"
#include "UserAccount.h"
#include <iostream>

int main()
{
    TcpConnection connection;
    UserAccount account = readObjectFromConnection<UserAccount>(connection);

    return EXIT_SUCCESS;
}
// g++ -I include/ -o main main.cpp TcpConnection.cpp UserAccount.cpp