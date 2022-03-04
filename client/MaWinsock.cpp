#include <iostream>
#include "Erreur.h"
#include "MaWinsock.h"

using namespace std;

MaWinsock * MaWinsock::instanceUnique = nullptr;

MaWinsock * MaWinsock::getInstance() {
    if (!instanceUnique) instanceUnique = new MaWinsock;
    return instanceUnique;
}


MaWinsock::MaWinsock()
{
    int r;
    r = WSAStartup( MAKEWORD(2,0), &wsaData);
    if (r) throw Erreur("L'initialisation a echoue");
    cout << "Initialisation de la Winsock reussie."<<endl;
}


MaWinsock::~MaWinsock()
{
    WSACleanup();
    cout << "Suppression de la winsock effectuee."<<endl;
}