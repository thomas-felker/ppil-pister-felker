#pragma once
#include "Forme.h"

using namespace std;

class Segment : public Forme {
private:

public:
    Segment(const string &couleur, const vector<Vecteur2D *> &points);

    ~Segment() override = default;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;
};