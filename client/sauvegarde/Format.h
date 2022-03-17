//
// Created by satom on 05/03/2022.
//

#ifndef CLIENT_FORMAT_H
#define CLIENT_FORMAT_H

#include <string>
#include <regex>
#include "Erreur.h"
#include "client/ClientDessin.h"

using namespace std;

class Forme;

class Format {
private:
    Format * suivant_;
public:


    /**
     * 
     * @brief Constructeur    
     * 
     * */
    Format(Format *suivant = nullptr);

    /**
     * 
     * @brief Destructeur  
     * 
     * */
    virtual ~Format();


    /**
     * 
     * @brief Permet de sauvegarder la requete voulu 
     * 
     * */
    virtual void save(string query, string filename) = 0;


    virtual explicit operator string() { return ""; }
};


#endif //CLIENT_FORMAT_H
