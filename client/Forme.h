#pragma once

#include <string>
#include <cstring>
#include <sstream>
#include <ostream>
#include "Vecteur2D.h"

using namespace std;

class Forme {
private :
    string nom_, couleur_;
    Vecteur2D * marges_;

public :
    Forme(const string &nom, const string &couleur, Vecteur2D *marges) : nom_(nom), couleur_(couleur),
                                                                         marges_(marges) {}

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
        return marges_->getX();
    }

    int getMargeGauche() const {
        return marges_->getY();
    }

    virtual ostringstream getQuery() = 0;
    virtual double calculerAire() = 0;

    virtual string toString() {
        string res = "Forme { " + nom_ + ", margeHaut : " + to_string(getMargeHaut());
        res = res + ", margeGauche : " + to_string(getMargeGauche()) + ", " + couleur_ + " }";
        return res;
    }
    virtual explicit operator string() { return toString(); }

    bool operator==(const Forme &rhs) const {
        return nom_ == rhs.nom_ &&
               couleur_ == rhs.couleur_ &&
               marges_ == rhs.marges_;
    }

    bool operator!=(const Forme &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Forme &rhs) const {
        if (nom_ < rhs.nom_)
            return true;
        if (rhs.nom_ < nom_)
            return false;
        if (couleur_ < rhs.couleur_)
            return true;
        if (rhs.couleur_ < couleur_)
            return false;
        return marges_ < rhs.marges_;
    }

    bool operator>(const Forme &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Forme &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Forme &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const Forme &forme) {
        os << "nom_: " << forme.nom_ << " couleur_: " << forme.couleur_ << " marges_: " << forme.marges_;
        return os;
    }
};