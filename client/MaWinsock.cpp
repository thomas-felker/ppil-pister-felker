#include <iostream>
#include "Erreur.h"
#include "MaWinsock.h"

using namespace std;

/* static */ MaWinsock * MaWinsock::instanceUnique = NULL;

/* static */ MaWinsock * MaWinsock::getInstance()
{
    if (!instanceUnique) instanceUnique = new MaWinsock;
    return instanceUnique;
}


MaWinsock::MaWinsock(void)
{
    int r;

    r = WSAStartup( MAKEWORD(2,0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

    if (r) throw Erreur("L'initialisation a echoue");

    cout << "Initialisation Winsock effectuee"<<endl;
}


MaWinsock::~MaWinsock(void)
{
    WSACleanup();
    cout << "Liberation des ressources de la winsock effectuee"<<endl;
}