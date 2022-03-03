/*
 * ClientDessin.cpp
 *
 *  Created on: 26 août 2014
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

ClientDessin::ClientDessin( const string & adresseServeurDessin, const int portServeurDessin)
{
    MaWinsock::getInstance();	// initialisation de la DLL : effectuée une seule fois

//---------------------- création socket -------------------------------------------------
    int r;

    int familleAdresses = AF_INET;         // IPv4
    int typeSocket = SOCK_STREAM;           // mode connecté TCP
    int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
    // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

    sock =  socket( familleAdresses, typeSocket, protocole);

    if (sock == INVALID_SOCKET)
    {
        ostringstream oss;
        oss << "la creation du socket a echoue : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
        throw Erreur(oss.str().c_str());
    }

    cout << "Socket de dessin cree" << endl;

//------------------------------ création du représentant du serveur ----------------------------------------

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());   // inet_addr() convertit de l'ASCII en entier
    sockaddr.sin_port = htons((short)portServeurDessin);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

    r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
    // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

    if (r == SOCKET_ERROR)
        throw Erreur("La connexion au serveur de dessin a echoue");

    cout << "Connexion au serveur de dessin reussie" << endl;
}

ClientDessin::~ClientDessin()
{
    int r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
    // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

    if (r == SOCKET_ERROR)
        throw Erreur("La coupure de connexion a echoue");


    r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
    if (r) throw Erreur("La fermeture du socket a echoue");

    cout << "Arret normal du client" << endl;
}


void ClientDessin::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
    ostringstream oss;

    oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

    string requete = oss.str();


    //int l = strlen(requete);

    int r = send( sock, requete.c_str(), requete.length(), 0);             //------------------ envoi de la requête au serveur -------------------------------

    if (r == SOCKET_ERROR)
        throw Erreur("échec de l'envoi de la requete d'ouverture de fenêtre graphique");

    cout << "Requete d'ouverture de fenetre graphique envoyee" << endl;
}

SOCKET ClientDessin::getSock() const {
    return sock;
}
void ClientDessin::setSock(SOCKET sock) {
    ClientDessin::sock = sock;
}

const SOCKADDR_IN &ClientDessin::getSockaddr() const {
    return sockaddr;
}
void ClientDessin::setSockaddr(const SOCKADDR_IN &sockaddr) {
    ClientDessin::sockaddr = sockaddr;
}

void ClientDessin::envoyer(ostringstream query) {
    string requete = query.str();
    int r = send(sock, requete.c_str(), requete.length(), 0);
    if (r == SOCKET_ERROR)
        throw Erreur("Echec de l'envoi de la requete");
}

void ClientDessin::envoyer(string query) {
    string requete = query + "\r \n";
    int r = send(sock, requete.c_str(), requete.length(), 0);
    if (r == SOCKET_ERROR)
        throw Erreur("Echec de l'envoi de la requete");
    cout << "Requete envoyee : " << query << endl;
}

void ClientDessin::initCadre(Vecteur2D * marge, Vecteur2D * dim) {
    ostringstream oss;
    oss << "cadre:Frame," << marge->getX() << "," << marge->getY() << "," << dim->getX()
    << "," << dim->getY() << "\r\n";
    int r = send(sock, oss.str().c_str(), oss.str().length(), 0);
    if (r == SOCKET_ERROR)
        throw Erreur("échec de l'envoi de la requête");
};