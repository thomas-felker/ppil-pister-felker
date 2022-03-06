

#include <winsock2.h>
#include <string.h>
#include <string>
#include <sstream>
#include "Erreur.h"
#include "client/Winsock.h"
#include "ClientDessin.h"

using namespace std;



ClientDessin::ClientDessin( const string & adresseServeurDessin, const int portServeurDessin)
{
    Winsock::getInstance();	

    int r;

    int familleAdresses = AF_INET;         
    int typeSocket = SOCK_STREAM;           
    int protocole = IPPROTO_TCP;            

    sock =  socket( familleAdresses, typeSocket, protocole);

    if (sock == INVALID_SOCKET)
    {
        ostringstream oss;
        oss << "la creation du socket a echoue : code d'erreur = " << WSAGetLastError() << endl;	
        throw Erreur(oss.str().c_str());
    }

    cout << "Socket de dessin cree" << endl;


    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = inet_addr(adresseServeurDessin.c_str());  
    sockaddr.sin_port = htons((short)portServeurDessin);                 


    r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));    

    if (r == SOCKET_ERROR)
        throw Erreur("La connexion au serveur de dessin a echoue");

    cout << "Connexion au serveur de dessin reussie" << endl;
}

ClientDessin::~ClientDessin()
{
    int r = shutdown(sock,SD_BOTH);						
    

    if (r == SOCKET_ERROR)
        throw Erreur("La coupure de connexion a echoue");


    r = closesocket(sock);                         
    if (r) throw Erreur("La fermeture du socket a echoue");

    cout << "Arret normal du client" << endl;
}


void ClientDessin::ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur)
{
    ostringstream oss;

    oss << titre << ", " << bordGauche << ", " << bordHaut << ", " << largeur << ", " << hauteur << "\r\n";

    string requete = oss.str();



    int r = send( sock, requete.c_str(), requete.length(), 0);             

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