#include "Groupe.h"

Groupe::Groupe(const string &couleur, const list<Forme *> &formes) :
    formes(formes), couleur(couleur) {
    for(_List_const_iterator<Forme *> it = formes.begin(); it != formes.end(); it++) {
        (*it)->setCouleur(couleur);
    }
}

Groupe::~Groupe() {}

void Groupe::dessiner(LibrairieGraphique *Librairie) {
    for(_List_const_iterator<Forme *> it = formes.begin(); it != formes.end(); it++) {
        (*it)->dessiner(Librairie);
    }
}

void Groupe::translation(Vecteur2D d) {
    for(_List_const_iterator<Forme *> it = formes.begin(); it != formes.end(); it++) {
        (*it)->translation(d);
    }
}

double Groupe::calculerAire() {
    double res = 0;
    for(_List_const_iterator<Forme *> it = formes.begin(); it != formes.end(); it++) {
        res = res + (*it)->calculerAire();
    }
    return res;
}