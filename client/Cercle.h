#pragma once

#include "Forme.h"
#include <math.h>

using namespace std;

class Cercle : public Forme {
private:
    double largeur_, hauteur_;

public:
    Cercle(const string &couleur, const int margeHaut, const int margeGauche, double rayon);
    Cercle(const string &couleur, const int margeHaut, const int margeGauche, double largeur,
           double hauteur);

    virtual ~Cercle();

    double getLargeur() const;
    void setLargeur(double largeur);

    double getHauteur() const;
    void setHauteur(double hauteur);

    ostringstream getQuery() override;

    double calculerAire() override;

    string toString() override;
    explicit operator string() override;
};
