#include "Cercle.h"

Cercle::Cercle(const string &couleur, const vector<Vecteur2D *> &points, double rayon) :
        Forme("Cercle",couleur,points),rayon(rayon) {
    if (rayon < 0) {
        throw Erreur("rayon < 0");
    }
}

Cercle::~Cercle() = default;

double Cercle::getRayon() const {
    return rayon;
}

double Cercle::calculerAire() {
    return rayon * rayon * M_PI;
}

void Cercle::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerCercle(this);
}

Cercle::operator string() {
    return Forme::operator string() + + "," + to_string(int(rayon));
}

void Cercle::homothetie(const double k, const Vecteur2D &invariant) {
    Forme::homothetie(k, invariant);
    this->rayon = this->rayon * k;
}

void Cercle::homothetie(const double k, const Vecteur2D *invariant) {
    Forme::homothetie(k, invariant);
    this->rayon = this->rayon * k;
}

