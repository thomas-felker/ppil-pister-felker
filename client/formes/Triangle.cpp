#include "Triangle.h"

Triangle::Triangle(const string &couleur, const vector<Vecteur2D *> &points) :
    Forme("Triangle", couleur,points) {}

Triangle::~Triangle() = default;

double Triangle::calculerAire() {
    Vecteur2D AB = *getPoint(1) - *getPoint(0);
    Vecteur2D AC = *getPoint(2) - *getPoint(0);
    double res = (0.5 * AB.determinant(AC));
    return abs(res);
}

void Triangle::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerTriangle(this);
}