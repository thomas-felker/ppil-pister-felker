#pragma once
/*
 * ClientDessin.h
 *
 *  Created on: 26 août 2014
 *      Author: Dominique
 */


#include <WinSock2.h>
#include <string>
#include <string.h>

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
ClientDessin( const string & adresseServeurDessin, const int portServeurDessin);
~ClientDessin();

void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

/**
    envoie sur une seule ligne les 5 paramètres au serveur.
 * Les 5 paramètres drawLine, ... , y2 sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
 *  * */
void traceSegment( const int x1, const int y1, const int x2, const int y2);

/**
envoie sur une seule ligne les 5 paramètres au serveur.
* Les 5 paramètres fillOval, ... , hauteur sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
*  * */
void remplitEllipse( const int bordGauche, const int bordHaut, const int largeur, const int hauteur);
};



