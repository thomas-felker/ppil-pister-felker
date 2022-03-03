#pragma once
#include "Forme.h"

class Triangle : public Forme {
private:
    Vecteur2D * pointA, * pointB;
public:
    Triangle(const string &couleur, Vecteur2D *pos, Vecteur2D *pointA, Vecteur2D *pointB);

    virtual ~Triangle();

    string getQuery() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;

    string toString() override;

    void translation(Vecteur2D d) override;

    explicit operator string() override;
};