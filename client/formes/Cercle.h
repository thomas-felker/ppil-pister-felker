#pragma once

#include "Forme.h"
#include <ostream>


using namespace std;

class Cercle : public Forme {
private:
    double rayon;
public:
    Cercle(const string &couleur, const vector<Vecteur2D *> &points, double rayon);
    ~Cercle() override;

    double getRayon() const;
    double calculerAire() override;

    void homothetie(const double k, const Vecteur2D &invariant) override;

    void homothetie(const double k, const Vecteur2D *invariant) override;

    void dessiner(LibrairieGraphique *Librairie) override;

    explicit operator string() override;
};
