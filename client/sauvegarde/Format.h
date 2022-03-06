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

    /**
     * 
     * @brief permet de charger la requete voulu 
     * 
     * */
    virtual void charger(ClientDessin & client, string filename) = 0;
    /**
     * 
     * @brief méthode utilisant le pattern COR qui vérifie si l'on sait comment charger ce type de fichier  
     * 
     * */
    virtual bool saitCharger(string type) = 0;


    /**
     * 
     * @brief méthode qui charge la requete sauvegarder dans un fichier et l'envoie au serveur pour la dessiner    
     * 
     * */
    virtual void load(ClientDessin & client, const string & filename, const string & type) {
        if (saitCharger(type)) {
            charger(client, "../sauvegarde/saves/"+filename);
        } else if (suivant_ != nullptr) {
            suivant_->load(client, filename, type);
        } else {
            Erreur("Erreur : Format inconnu");
        }
    }

    virtual explicit operator string() { return ""; }
};


#endif //CLIENT_FORMAT_H
