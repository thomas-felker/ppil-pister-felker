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

r = WSAStartup( MAKEWORD(2,0), &wsaData);       // MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2

/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

if (r) throw Erreur("L'initialisation a �chou�");

cout << "initialisation winsock effectu�e"<<endl;
}


MaWinsock::~MaWinsock(void)
{
WSACleanup();
cout << "lib�ration des ressources de la winsock effectu�e"<<endl;
}
