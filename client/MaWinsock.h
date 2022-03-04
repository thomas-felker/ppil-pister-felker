#pragma once

#include <WinSock2.h>

class MaWinsock
{
    WSADATA wsaData;
    MaWinsock();
    static MaWinsock * instanceUnique;

public:
    static MaWinsock * getInstance();
    ~MaWinsock();
};