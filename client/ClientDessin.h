#pragma once

#include <WinSock2.h>
#include <string>
#include <string.h>
#include <sstream>
#include "Vecteur2D.h"

using namespace std;

/**
 * crée un client TCP/IP vers un serveur de dessin
 *
 * envoie 3 requêtes possibles :
 *
 * ouvrir une fenêtre graphique
 * tracer un segment
 * tracer une ellipse pleine
 *
 * protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
 * Sur la ligne, 2 paramètres consécutifs sont séparés par ", ".
 *
 * */
class ClientDessin
{
    SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole 
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