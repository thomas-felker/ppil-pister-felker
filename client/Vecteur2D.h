#pragma once
#include <sstream>

using namespace std;

/**
	Représente un point du plan
*/

class Vecteur2D
{
private:
	double _x, _y;

public:
	explicit Vecteur2D (const double x = 0, const double y = 0) : _x(x), _y(y) {}

	/* Opérateurs */
	const Vecteur2D operator + (const Vecteur2D& v) const { return Vecteur2D(_x+v._x, _y+v._y); }
	const Vecteur2D operator - () const { return Vecteur2D(-_x, -_y); }
	const Vecteur2D operator * (const double a) { return Vecteur2D(a * _x, a * _y); }
	operator string () const {
		ostringstream os;
		os << "(" << _x << ", " << _y << ")";
		// return os.string();
	}
};