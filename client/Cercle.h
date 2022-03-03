#pragma once

#include "Forme.h"
#include <ostream>


using namespace std;

class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(const string &couleur, Vecteur2D *pos, double rayon);
    virtual ~Cercle();

    double getRayon() const;

    string getQuery() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;

    string toString() override;

    void translation(Vecteur2D d) override;

    explicit operator string() override;
};
