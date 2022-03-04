#pragma once
#include "Forme.h"

class Triangle : public Forme {
private:

public:
    Triangle(const string &couleur, const vector<Vecteur2D *> &points);

    ~Triangle() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;
};