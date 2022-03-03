#include "Cercle.h"

Cercle::Cercle(const string &couleur, Vecteur2D *pos, double rayon) :
    Forme(couleur, pos), rayon(rayon) {}
Cercle::~Cercle() {

}

double Cercle::getRayon() const {
    return rayon;
}

string Cercle::getQuery() {
    return this->toString();
}

double Cercle::calculerAire() {
    return rayon * rayon * M_PI;
}

void Cercle::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerCercle(this);
}

string Cercle::toString() {
    string res = "Cercle:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut())) + ","
                 + to_string(int(rayon)) + "\r \n";
    return res;
}

Cercle::operator string() {
    string res = "Cercle:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut())) + ","
                 + to_string(int(rayon));
    return res;
}

void Cercle::translation(Vecteur2D d) {
    setPos(new Vecteur2D((*getPos()) + d));
}

