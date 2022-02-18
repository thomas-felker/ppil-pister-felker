#include "Segment.h"

Segment::~Segment() {}

bool Segment::operator==(const Segment &rhs) const {
    return static_cast<const Forme &>(*this) == static_cast<const Forme &>(rhs) &&
           arrivee_ == rhs.arrivee_;
}

bool Segment::operator!=(const Segment &rhs) const {
    return !(rhs == *this);
}

bool Segment::operator<(const Segment &rhs) const {
    if (static_cast<const Forme &>(*this) < static_cast<const Forme &>(rhs))
        return true;
    if (static_cast<const Forme &>(rhs) < static_cast<const Forme &>(*this))
        return false;
    return arrivee_ < rhs.arrivee_;
}

bool Segment::operator>(const Segment &rhs) const {
    return rhs < *this;
}

bool Segment::operator<=(const Segment &rhs) const {
    return !(rhs < *this);
}

bool Segment::operator>=(const Segment &rhs) const {
    return !(*this < rhs);
}

double Segment::calculerAire() {
    return 0;
}

string Segment::toString() {
    return Forme::toString();
}

Segment::operator string() {
    return Forme::operator string();
}

ostream &operator<<(ostream &os, const Segment &segment) {
    os << static_cast<const Forme &>(segment) << " arrivee_: " << segment.arrivee_;
    return os;
}

ostringstream Segment::getQuery() {
    ostringstream oss;
    oss << getNom() << ", " << getCouleur() << ", " << getMargeGauche() << ", " << getMargeHaut() << ", " << getX2() << ", " << getY2();
    return oss;
}

Segment::Segment(const string &couleur, Vecteur2D *marges, Vecteur2D *arrivee) : Forme("Segment", couleur, marges),arrivee_(arrivee) {}
