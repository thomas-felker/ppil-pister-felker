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

    bool operator==(const Vecteur2D &rhs) const;

    bool operator!=(const Vecteur2D &rhs) const;

    bool operator<(const Vecteur2D &rhs) const;

    bool operator>(const Vecteur2D &rhs) const;

    bool operator<=(const Vecteur2D &rhs) const;

    bool operator>=(const Vecteur2D &rhs) const;

    friend ostream &operator<<(ostream &os, const Vecteur2D &d);
};

// template <class T>

/* inline const T operator - (const T & u, const T & v)
{
    return u + -v;
}
class Vecteur2D
{
public:
    double x,y;
    inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

*/

/**
* DONNEES : s respectant le format "( nombre réel, nombre réel)"
*
* */
/*
    inline Vecteur2D(const char * s);
    inline const Vecteur2D operator + (const Vecteur2D & u) const;
    inline const Vecteur2D operator * (const double & a) const;
*/

/**
* - unaire (c'est-à- dire opposé d'un vecteur)
* */

/*
    inline const Vecteur2D operator - () const;
    ..............
    autres méthodes
    ...................
    operator string() const;
};

// classe Vecteur2D
inline const Vecteur2D operator *(const double & a, const Vecteur2D & u)
{ return u*a;}
//------------ implémentation des fonctions inline ---------------------

inline Vecteur2D::
Vecteur2D(const double & x, const double & y): x(x),y(y){}
inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}
inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}
inline const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}
Vecteur2D::operator string() const
{
    ostringstream os;
    os << "( " << x <<", " << y << ")";
    return os.str();
}
ostream & operator << (ostream & os, const Vecteur2D & u)
{
    os << (string) u;
    return os;
}
*/