#pragma once
#include <sstream>
#include <ostream>

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

    Vecteur2D rotation(const double rad, const Vecteur2D& invariant)
    {
        /*
        Matrice2x2 R = Matrice2x2::creeRotation(rad);
        return Vecteur2D(R * (V - invariant) + invariant);
         */
        return *this;
    }

    Vecteur2D operator * (const double k) const {
        return {getX() * k, getY() * k};
    }

    Vecteur2D operator + (const Vecteur2D & v) const;
    Vecteur2D operator + (const Vecteur2D * v) const;

    Vecteur2D operator - (const Vecteur2D & v) const;
    Vecteur2D operator - (const Vecteur2D * v) const;

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