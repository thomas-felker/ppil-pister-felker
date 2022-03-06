#pragma once
#include <sstream>
#include <ostream>
#include "Matrice.h"

using namespace std;

class Vecteur2D {
private :
    double x,y;
public :
    Vecteur2D(double x, double y);
    virtual ~Vecteur2D();

    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

    double determinant(Vecteur2D op)const;

    Vecteur2D homotetie(const double k, const Vecteur2D& invariant) const {
        return Vecteur2D((*this) * k + invariant * (1 - k));
    }

    Vecteur2D rotation(const double teta, const Vecteur2D& invariant)
    {
        Matrice M = Matrice::creerMatRotation(teta);
        return Vecteur2D((*this - invariant) * M + invariant);
    }


    Vecteur2D operator * (Matrice M) const {
        return {getX() * M.getA() + getY() * M.getC(), getX() * M.getB() + getY() * M.getD()};
    }

    Vecteur2D operator * (const double k) const {
        return {getX() * k, getY() * k};
    }

    Vecteur2D operator + (const Vecteur2D & v) const;
    Vecteur2D operator + (const Vecteur2D * v) const;

    Vecteur2D operator - (const Vecteur2D & v) const;
    Vecteur2D operator - (const Vecteur2D * v) const;
    Vecteur2D operator - () const;

    explicit operator string() const {
        string res = "Vecteur : x=" + to_string(x) + ", y=" + to_string(y);
        return res;
    }
    string toString() const {
        string res = "Vecteur : x=" + to_string(x) + ", y=" + to_string(y);
        return res;
    }

    bool operator==(const Vecteur2D &rhs) const;
    bool operator!=(const Vecteur2D &rhs) const;
    bool operator<(const Vecteur2D &rhs) const;
    bool operator>(const Vecteur2D &rhs) const;
    bool operator<=(const Vecteur2D &rhs) const;
    bool operator>=(const Vecteur2D &rhs) const;

    friend ostream &operator<<(ostream &os, const Vecteur2D &d);
};