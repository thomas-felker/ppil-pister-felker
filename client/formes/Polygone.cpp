#include "Polygone.h"
#include "Triangle.h"

using namespace std;

Polygone::Polygone(const string &couleur, const vector<Vecteur2D *> &points) :
        Forme("Polygone", couleur, points) {}

Polygone::~Polygone() = default;

double Polygone::calculerAire() {
    double res = 0;
    for(int i = 0 ; i < getPoints().size()-1; i++)
    {
        vector<Vecteur2D *> v;
        v.push_back(getPoint(0));
        v.push_back(getPoint(i));
        v.push_back(getPoint(i+1));
        Triangle t(getCouleur(),v);
        res += t.calculerAire();
    }
    return res;
}

void Polygone::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerPolygone(this);
}