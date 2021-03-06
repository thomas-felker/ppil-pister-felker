#pragma once

#include "Forme.h"
#include "libgraphique/LibrairieGraphique.h"
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
    void homothetie (const double k, const Vecteur2D& invariant) override;

    void rotation (const double teta, const Vecteur2D & invariant) override;

    void mondeEcran(const Vecteur2D &dim) override;

    double calculerAire() override;

    explicit operator string() override;

    double calculerAire1();

    Groupe(const string couleur, vector<struct Forme *> formes);
};
