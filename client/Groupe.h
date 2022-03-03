#pragma once

#include "Forme.h"
#include "LibrairieGraphique.h"
#include <list>

class Groupe {
private:
    string couleur;
    list<Forme *> formes;
public:
    Groupe(const string &couleur, const list<Forme *> &formes);
    virtual ~Groupe();

    void dessiner(LibrairieGraphique *Librairie);

    void translation(Vecteur2D d);

    double calculerAire();
};
