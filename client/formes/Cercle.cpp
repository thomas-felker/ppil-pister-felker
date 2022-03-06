#include "Cercle.h"

Cercle::Cercle(const string &couleur, const vector<Vecteur2D *> &points, double rayon) :
        Forme("Cercle",couleur,points),rayon(rayon) {}

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
