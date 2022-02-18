#pragma once

#include "Forme.h"
#include <math.h>
#include <ostream>

using namespace std;

class Cercle : public Forme {
private:
    Vecteur2D * dimensions_;

public:
    Cercle(const string &couleur, Vecteur2D *marges, Vecteur2D *dimensions);
    virtual ~Cercle();

    Vecteur2D *getDimensions() const;
    void setDimensions(Vecteur2D *dimensions);

    double getLargeur() const {
        return dimensions_->getX();
    }

    double getHauteur() const {
        return dimensions_->getY();
    }

    bool operator==(const Cercle &rhs) const;
    bool operator!=(const Cercle &rhs) const;
    bool operator<(const Cercle &rhs) const;
    bool operator>(const Cercle &rhs) const;
    bool operator<=(const Cercle &rhs) const;
    bool operator>=(const Cercle &rhs) const;
    friend ostream &operator<<(ostream &os, const Cercle &cercle);

    ostringstream getQuery() override;
    double calculerAire() override;
    string toString() override;
    explicit operator string() override;
};
