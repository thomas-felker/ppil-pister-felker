#pragma once

#include "Forme.h"
#include "LibrairieGraphique.h"
#include <vector>

class Groupe : public Forme {
private:
    vector<Forme *> formes;
public:
    Groupe(const string &couleur, const vector<Vecteur2D *> &points, const vector<Forme *> &formes);
    ~Groupe() override;

    void dessiner(LibrairieGraphique *Librairie) override;

    void translation(Vecteur2D *d) override;
    void translation(Vecteur2D d) override;

    double calculerAire() override;
};
