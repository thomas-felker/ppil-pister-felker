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
    Format(Format *suivant = nullptr);

    virtual ~Format();

    virtual void save(string query, string filename) = 0;
    virtual void charger(ClientDessin & client, string filename) = 0;
    virtual bool saitCharger(string type) = 0;

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
