#pragma once
#include "formes/Forme.h"
#include <vector>

class Polygone : public Forme {
private:
public:
    Polygone(const string &couleur, const vector<Vecteur2D *> &points);

    ~Polygone() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;
};
