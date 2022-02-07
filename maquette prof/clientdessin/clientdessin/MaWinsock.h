#pragma once

/**
singleton contenant l'initialisation de la librairie winsock2.

Assure que la DLL de la winsock est initialis�e une unique fois 

*/

#include <WinSock2.h>
#pragma comment(lib, "ws2_32")

class MaWinsock
{
WSADATA wsaData;	//  structure contenant les donn�es de la librairie winsock � initialiser. repr�sente la DLL.
MaWinsock(void);

static MaWinsock * instanceUnique;
public:
static MaWinsock * getInstance();
~MaWinsock(void);
};

