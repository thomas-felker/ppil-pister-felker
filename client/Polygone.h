#pragma once
#include "Forme.h"
#include <list>

class Polygone : public Forme {
private:
    list<Vecteur2D *> points;
public:
    Polygone(const string &couleur, Vecteur2D *pos, const list<Vecteur2D *> &points);

    virtual ~Polygone();

    string getQuery() override;

    double calculerAire() override;

    void dessiner(LibrairieGraphique *Librairie) override;

    void translation(Vecteur2D d) override;

    string toString() override;

    explicit operator string() override;
};
