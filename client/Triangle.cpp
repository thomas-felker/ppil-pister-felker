#include "Triangle.h"

Triangle::Triangle(const string &couleur, Vecteur2D *pos, Vecteur2D *pointA, Vecteur2D *pointB)
        : Forme(couleur, pos), pointA(pointA), pointB(pointB) {}


Triangle::~Triangle() {

}

string Triangle::getQuery() {
    return this->toString();
}

double Triangle::calculerAire() {
    Vecteur2D AB = (*getPos()) - (*pointA) ;
    Vecteur2D AC = (*getPos()) - (*pointB);
    double res = (0,5 * AB.determinant(AC));
    if (res < 0) return -res;
    else return res;
}

void Triangle::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerTriangle(this);
}

string Triangle::toString() {
    string res = "Triangle:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut())) + ","
                 + to_string(int(pointA->getX())) + ","
                 + to_string(int(pointA->getY())) + ","
                 + to_string(int(pointB->getX())) + ","
                 + to_string(int(pointB->getY()));
    return res;
}

Triangle::operator string() {
    string res = "Triangle:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut())) + ","
                 + to_string(int(pointA->getX())) + ","
                 + to_string(int(pointA->getY())) + ","
                 + to_string(int(pointB->getX())) + ","
                 + to_string(int(pointB->getY()));
    return res;
}

void Triangle::translation(Vecteur2D d) {
    setPos(new Vecteur2D((*getPos()) + d));
    pointA = new Vecteur2D((*pointA) + d);
    pointB = new Vecteur2D((*pointB) + d);
}
