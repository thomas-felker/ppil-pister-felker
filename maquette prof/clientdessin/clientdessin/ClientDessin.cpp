
/*
 * ClientDessin.cpp
 *
 *  Created on: 26 ao�t 2014
 *      Author: Dominique
 */

#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include "Erreur.h"
#include "MaWinsock.h"
#include "ClientDessin.h"

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

ClientDessin::ClientDessin( const string & adresseServeurDessin, const int portServeurDessin)
{
MaWinsock::getInstance();	// initialisation de la DLL : effectu�e une seule fois


//---------------------- cr�ation socket -------------------------------------------------

int r;

int familleAdresses = AF_INET;         // IPv4
int typeSocket = SOCK_STREAM;           // mode connect� TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers param�tres
                                        // pour les valeurs des param�tres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
  throw Erreur(oss.str().c_str());
  }

cout << "socket de dessin cr��" << endl;

//------------------------------ cr�ation du repr�sentant du serveur ----------------------------------------

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
                                                                // Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
  throw Erreur("La connexion au serveur de dessin a �chou�");

cout << "connexion au serveur de dessin r�ussie" << endl;
}

ClientDessin::~ClientDessin()
{
int r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la r�ception
													// renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

if (r == SOCKET_ERROR)
	throw Erreur("la coupure de connexion a �chou�");


r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'�chec. Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()
if (r) throw Erreur("La fermeture du socket a �chou�");

cout << "arr�t normal du client" << endl;
}

// il y a une GROSSE redondance de code (ou autrement dit un GROS copi�-coll� pourri) sur les 3 m�thodes suivantes : elle doit �tre �limin�e !!!!!!!
// cf. classe JAVA ClientDessin - m�thode encoder()

void ClientDessin::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te d'ouverture de fen�tre graphique");

cout << "requ�te d'ouverture de fen�tre graphique envoy�e" << endl;
}

/**
    envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
 *  * */
void ClientDessin::traceSegment( const int x1, const int y1, const int x2, const int y2)
{
ostringstream oss;

oss << "drawLine, " << x1 << ", " << y1 << ", " << x2 << ", " << y2 << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;
}

/**
envoie sur une seule ligne les 5 param�tres au serveur.
* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
*  * */
void ClientDessin::remplitEllipse( const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
ostringstream oss;

oss << "fillOval" << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

string requete = oss.str();


//int l = strlen(requete);

int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requ�te au serveur -------------------------------
                                                
if (r == SOCKET_ERROR)
   throw Erreur("�chec de l'envoi de la requ�te de trac� de segment");

cout << "requ�te de trac� de segment envoy�e" << endl;
}