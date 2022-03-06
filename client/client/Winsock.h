#pragma once

#include <winsock2.h>

class Winsock
{
    WSADATA wsaData;
    Winsock();
    static Winsock * instanceUnique;

public:

    /**
     * 
     * @brief initialisation de l'instance 
     * 
     * */
    static Winsock * getInstance();
    ~Winsock();
};