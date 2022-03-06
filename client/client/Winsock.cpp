#include <iostream>
#include "Erreur.h"
#include "Winsock.h"

using namespace std;

Winsock * Winsock::instanceUnique = nullptr;

Winsock * Winsock::getInstance() {
    if (!instanceUnique) instanceUnique = new Winsock;
    return instanceUnique;
}


Winsock::Winsock()
{
    int r;
    r = WSAStartup( MAKEWORD(2,0), &wsaData);
    if (r) throw Erreur("L'initialisation a echoue");
    cout << "Initialisation de la Winsock reussie."<<endl;
}


Winsock::~Winsock()
{
    WSACleanup();
    cout << "Suppression de la winsock effectuee."<<endl;
}