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
