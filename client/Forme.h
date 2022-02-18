#pragma once

#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class Forme {
private :
    string nom_, couleur_;
    int margeHaut_, margeGauche_;

public :
    Forme(const string& nom, const int margeHaut, const int margeGauche, const string & couleur) {
        nom_ = nom;
        margeHaut_ = margeHaut;
        margeGauche_ = margeGauche;
        couleur_ = couleur;
    }
    virtual ~Forme(){};

    const string &getNom() const {
        return nom_;
    }

    void setNom(const string &nom) {
        nom_ = nom;
    }

    const string &getCouleur() const {
        return couleur_;
    }

    void setCouleur(const string &couleur) {
        couleur_ = couleur;
    }

    int getMargeHaut() const {
        return margeHaut_;
    }

    void setMargeHaut(int margeHaut) {
        margeHaut_ = margeHaut;
    }

    int getMargeGauche() const {
        return margeGauche_;
    }

    void setMargeGauche(int margeGauche) {
        margeGauche_ = margeGauche;
    }

    virtual ostringstream getQuery() = 0;
    virtual double calculerAire() = 0;

    virtual string toString() {
        string res = "Forme { " + nom_ + ", margeHaut : " + to_string(margeHaut_);
        res = res + ", margeGauche : " + to_string(margeGauche_) + ", " + couleur_ + " }";
        return res;
    }
    virtual explicit operator string() { return toString(); }
};