#include "Cercle.h"

Cercle::Cercle(const string &couleur, Vecteur2D *marges, Vecteur2D *dimensions) : Forme("Cercle", couleur,marges),dimensions_(dimensions) {}

Cercle::~Cercle() {

}

Vecteur2D *Cercle::getDimensions() const {
    return dimensions_;
}

void Cercle::setDimensions(Vecteur2D *dimensions) {
    dimensions_ = dimensions;
}

bool Cercle::operator==(const Cercle &rhs) const {
    return static_cast<const Forme &>(*this) == static_cast<const Forme &>(rhs) &&
           dimensions_ == rhs.dimensions_;
}

bool Cercle::operator!=(const Cercle &rhs) const {
    return !(rhs == *this);
}

bool Cercle::operator<(const Cercle &rhs) const {
    if (static_cast<const Forme &>(*this) < static_cast<const Forme &>(rhs))
        return true;
    if (static_cast<const Forme &>(rhs) < static_cast<const Forme &>(*this))
        return false;
    return dimensions_ < rhs.dimensions_;
}

bool Cercle::operator>(const Cercle &rhs) const {
    return rhs < *this;
}

bool Cercle::operator<=(const Cercle &rhs) const {
    return !(rhs < *this);
}

bool Cercle::operator>=(const Cercle &rhs) const {
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const Cercle &cercle) {
    os << static_cast<const Forme &>(cercle) << " dimensions_: " << cercle.dimensions_;
    return os;
}

ostringstream Cercle::getQuery() {
    ostringstream oss;
    oss << getNom() << ", " << getCouleur() << ", " << getMargeGauche() << ", " << getMargeHaut() << ", " << getLargeur() << ", " << getHauteur();
    string query = oss.str();
    return oss;
}

double Cercle::calculerAire() {
    return getLargeur() * getHauteur() * M_PI;
}

string Cercle::toString() {
    return Forme::toString();
}

Cercle::operator string() {
    return Forme::operator string();
}
