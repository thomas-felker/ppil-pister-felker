#include "Polygone.h"

Polygone::Polygone(const string &couleur, Vecteur2D *pos, const list<Vecteur2D *> &points) :
        Forme(couleur, pos),points(points) {}

Polygone::~Polygone() {}

string Polygone::getQuery() {
    cout << "requete: " << this->toString();
    return this->toString();
}

double Polygone::calculerAire() {
    return 0;
}

void Polygone::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerPolygone(this);
}

string Polygone::toString() {
    string res = "Polygone:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut()));
    for(list<Vecteur2D *>::iterator it = points.begin(); it != points.end(); it++) {
        res = res + "," + to_string(int((*it)->getX())) + ","
              + to_string(int((*it)->getY()));
    }
    return res +"\r \n";
}

Polygone::operator string() {
    string res = "Polygone:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut()));
    for(list<Vecteur2D *>::iterator it = points.begin(); it != points.end(); it++) {
        res = res + "," + to_string(int((*it)->getX())) + ","
              + to_string(int((*it)->getY()));
    }
    return res +"\r \n";
}

void Polygone::translation(Vecteur2D d) {
    setPos(new Vecteur2D((*getPos()) + d));
    for(list<Vecteur2D *>::iterator it = points.begin(); it != points.end(); it++) {
        (*it) = new Vecteur2D((*(*it)) + d);
    }
}
