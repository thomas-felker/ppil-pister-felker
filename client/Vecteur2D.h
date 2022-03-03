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

    const Vecteur2D operator + (const Vecteur2D & v) const;
    const Vecteur2D operator + (const Vecteur2D * v) const;

    const Vecteur2D operator - (const Vecteur2D & v) const;
    const Vecteur2D operator - (const Vecteur2D * v) const;

    bool operator==(const Vecteur2D &rhs) const;
    bool operator!=(const Vecteur2D &rhs) const;
    bool operator<(const Vecteur2D &rhs) const;
    bool operator>(const Vecteur2D &rhs) const;
    bool operator<=(const Vecteur2D &rhs) const;
    bool operator>=(const Vecteur2D &rhs) const;

    friend ostream &operator<<(ostream &os, const Vecteur2D &d);
};