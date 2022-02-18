#pragma once

#include <ostream>
#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Segment : public Forme {
private :
    Vecteur2D * arrivee_;
public :
    Segment(const string &couleur, Vecteur2D *marges, Vecteur2D *arrivee);

    virtual ~Segment();

    const Vecteur2D &getArrivee() const;

    double getX2() const { return arrivee_->getX(); }

    double getY2() const { return arrivee_->getY(); }

    bool operator==(const Segment &rhs) const;

    bool operator!=(const Segment &rhs) const;

    bool operator<(const Segment &rhs) const;

    bool operator>(const Segment &rhs) const;

    bool operator<=(const Segment &rhs) const;

    bool operator>=(const Segment &rhs) const;

    double calculerAire() override;

    string toString() override;

    explicit operator string() override;

    ostringstream getQuery() override;

    friend ostream &operator<<(ostream &os, const Segment &segment);
};