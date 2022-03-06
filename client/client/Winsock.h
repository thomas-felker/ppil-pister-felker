#pragma once

#include <winsock2.h>

class Winsock
{
    WSADATA wsaData;
    Winsock();
    static Winsock * instanceUnique;

public:
    static Winsock * getInstance();
    ~Winsock();
};