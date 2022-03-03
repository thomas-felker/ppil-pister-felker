#pragma once

#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Segment : public Forme {
private:
    Vecteur2D * arrivee_;
public:
    Segment(const string &couleur, Vecteur2D *pos, Vecteur2D *arrivee);
    ~Segment() override;

    const Vecteur2D * getArrivee() const;

    string toString() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;

    explicit operator string() override;

    string getQuery() override;

    void translation(Vecteur2D d) override;
};