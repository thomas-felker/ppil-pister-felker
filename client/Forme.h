#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ostream>
#include <math.h>
#include "Vecteur2D.h"
#include "LibrairieGraphique.h"
// class LibrairieGraphique;

using namespace std;

class Forme {
private :
    string couleur_;
    Vecteur2D * pos_;

public :
    Forme(const string &couleur, Vecteur2D * pos) :
        couleur_(couleur), pos_(pos) {}
    virtual ~Forme(){};

    const string &getCouleur() const {
        return couleur_;
    }
    void setCouleur(const string &couleur) {
        couleur_ = couleur;
    }

    Vecteur2D *getPos() const {
        return pos_;
    }

    void setPos(Vecteur2D *pos) {
        pos_ = pos;
    }

    double getMargeHaut() const {
        return pos_->getY();
    }
    double getMargeGauche() const {
        return pos_->getX();
    }

    virtual string getQuery() = 0;
    virtual double calculerAire() = 0;
    virtual void dessiner(LibrairieGraphique * Librairie) = 0;

    virtual void translation(Vecteur2D) = 0;

    virtual string toString() {
        return "";
    }
    virtual explicit operator string() {
        return "";
    }
};