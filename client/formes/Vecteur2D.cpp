#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(double x, double y) : x(x), y(y) {}

Vecteur2D::~Vecteur2D() {}

double Vecteur2D::getX() const {
    return x;
}
void Vecteur2D::setX(double x) {
    Vecteur2D::x = x;
}

double Vecteur2D::getY() const {
    return y;
}
void Vecteur2D::setY(double y) {
    Vecteur2D::y = y;
}

double Vecteur2D::determinant(Vecteur2D op) const {
    return (getX() * op.getY() - getY()* op.getX());
}

// Opérateurs utiles


Vecteur2D Vecteur2D::operator + (const Vecteur2D & v) const {
    return {this->getX() + v.getX(), this->getY() + v.getY()};
}
Vecteur2D Vecteur2D::operator + (const Vecteur2D * v) const {
    return {this->getX() + v->getX(), this->getY() + v->getY()};
}

Vecteur2D Vecteur2D::operator - (const Vecteur2D & v) const{
    return {this->getX() - v.getX(), this->getY() - v.getY()};
}
Vecteur2D Vecteur2D::operator - (const Vecteur2D * v) const {
    return {this->getX() - v->getX(), this->getY() - v->getY()};
}

Vecteur2D Vecteur2D::operator - () const{
    return {0 - this->getX(), 0 - this->getY()};
}

// Autres pérateurs
ostream &operator<<(ostream &os, const Vecteur2D &d) {
    os << "x: " << d.x << " y: " << d.y;
    return os;
}

bool Vecteur2D::operator==(const Vecteur2D &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}
bool Vecteur2D::operator!=(const Vecteur2D &rhs) const {
    return !(rhs == *this);
}
bool Vecteur2D::operator<(const Vecteur2D &rhs) const {
    if (x < rhs.x)
        return true;
    if (rhs.x < x)
        return false;
    return y < rhs.y;
}
bool Vecteur2D::operator>(const Vecteur2D &rhs) const {
    return rhs < *this;
}
bool Vecteur2D::operator<=(const Vecteur2D &rhs) const {
    return !(rhs < *this);
}
bool Vecteur2D::operator>=(const Vecteur2D &rhs) const {
    return !(*this < rhs);
}