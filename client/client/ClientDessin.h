#pragma once

#include <winsock2.h>
#include <string>
#include <string.h>
#include <sstream>
#include "formes/Vecteur2D.h"

using namespace std;

/**
 * crée un client TCP/IP vers un serveur de dessin
 *
 *  avec un protocole défini ici par une chaine de caractère séparé par le symbole
 * ","
 * */

class ClientDessin
{
    SOCKET sock;   
    SOCKADDR_IN sockaddr; 

public:
    /**
     * 
     * @brief Constructeur  
     * 
     * */
    ClientDessin(const string& adresseServeurDessin, const int portServeurDessin);

    /**
     * 
     * @brief Destructeur   
     * 
     * */
    ~ClientDessin();


    /**
     * 
     * @brief Envoie la requete pour ouvrir le cadre de dessin 
     * 
     * */
    void ouvreFenetreGraphique(const string& titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

    SOCKET getSock() const;

    void setSock(SOCKET sock);

    const SOCKADDR_IN &getSockaddr() const;

    void setSockaddr(const SOCKADDR_IN &sockaddr);


    /**
     * 
     * @brief envoie de la requete au serveur   
     * 
     * */
    void envoyer(ostringstream query);
    void envoyer(string query);

    void initCadre(Vecteur2D * marge, Vecteur2D * dim);
};