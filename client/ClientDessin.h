#pragma once

#include <WinSock2.h>
#include <string>
#include <string.h>
#include <sstream>
#include "Vecteur2D.h"

using namespace std;

/**
 * cr�e un client TCP/IP vers un serveur de dessin
 *
 * envoie 3 requ�tes possibles :
 *
 * ouvrir une fen�tre graphique
 * tracer un segment
 * tracer une ellipse pleine
 *
 * protocole : Chaque requ�te est cod�e sous forme d'une seule String se terminant par le caract�re fin de ligne.
 * Sur la ligne, 2 param�tres cons�cutifs sont s�par�s par ", ".
 *
 * */
class ClientDessin
{
    SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole 
    SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

public:
    ClientDessin(const string& adresseServeurDessin, const int portServeurDessin);
    ~ClientDessin();

    void ouvreFenetreGraphique(const string& titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

    SOCKET getSock() const;

    void setSock(SOCKET sock);

    const SOCKADDR_IN &getSockaddr() const;

    void setSockaddr(const SOCKADDR_IN &sockaddr);

    void envoyer(ostringstream query);
    void envoyer(string query);

    void initCadre(Vecteur2D * marge, Vecteur2D * dim);
};