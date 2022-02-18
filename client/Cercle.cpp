#include "Cercle.h"

Cercle::Cercle(const string &couleur, const int margeHaut, const int margeGauche, double rayon)
        : Forme("Cercle", margeHaut, margeGauche, couleur) {
    largeur_ = rayon;
    hauteur_ = rayon;
}

Cercle::Cercle(const string &couleur, const int margeHaut, const int margeGauche, double largeur,
               double hauteur) : Forme("Cercle", margeHaut, margeGauche, couleur), largeur_(largeur), hauteur_(hauteur) {}

Cercle::~Cercle() {}

double Cercle::getLargeur() const {
    return largeur_;
}

void Cercle::setLargeur(double largeur) {
    largeur_ = largeur;
}

double Cercle::getHauteur() const {
    return hauteur_;
}

void Cercle::setHauteur(double hauteur) {
    hauteur_ = hauteur;
}

double Cercle::calculerAire() {
    return getHauteur() * getLargeur() * M_PI;
}

string Cercle::toString() {
    return Forme::toString();
}

Cercle::operator string() {
    return Forme::operator string();
}

ostringstream Cercle::getQuery() {
    ostringstream oss;
    oss << getNom() << ", " << getCouleur() << ", " << getMargeGauche() << ", " << getMargeHaut() << ", " << getLargeur() << ", " << getHauteur() << "\r\n";
    string query = oss.str();
    return oss;
}


