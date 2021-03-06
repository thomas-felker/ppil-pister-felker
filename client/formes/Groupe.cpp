#include "Groupe.h"

Groupe::Groupe(const string &couleur, const vector<Vecteur2D *> &points, const vector<Forme *> &formes)
        : Forme("Groupe", couleur, points), formes(formes) {
    for(int i = 0; i < formes.size(); i++) {
        formes[i]->setCouleur(couleur);
    }
}

Groupe::~Groupe() = default;

void Groupe::dessiner(LibrairieGraphique *Librairie) {
    for(int i = 0; i < formes.size(); i++) {
        formes[i]->dessiner(Librairie);
    }
}

double Groupe::calculerAire() {
    double res = 0;
    for(Forme * f : formes) {
        res += f->calculerAire();
    }
    return res;
}

double Groupe::calculerAire1() {
    double res = 0;
    for(int i = 0; i < formes.size(); i++) {
        res += formes[i]->calculerAire();
    }
    return res;
}

void Groupe::translation(Vecteur2D * d) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->translation(d);
    }
}

void Groupe::translation(Vecteur2D d) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->translation(d);
    }
}

void Groupe::homothetie (const double k, const Vecteur2D& invariant) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->homothetie(k, invariant);
    }
}

void Groupe::rotation (const double teta, const Vecteur2D & invariant) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->rotation(teta, invariant);
    }
}

void Groupe::mondeEcran(const Vecteur2D &dim) {
    for (int i = 0; i < formes.size(); i++) {
        formes[i]->mondeEcran(dim);
    }
}

Groupe::operator string() {
    string res = "Groupe:";
    for (int i = 0; i < formes.size(); i++) {
        res += string(*formes[i]) + "/";
    }
    return res;
}

Groupe::Groupe(const string couleur, vector<struct Forme *> formes) :
    Forme("Groupe", couleur, *(new vector<Vecteur2D *>)), formes(formes){
    for(int i = 0; i < formes.size(); i++) {
        formes[i]->setCouleur(couleur);
    }
}
