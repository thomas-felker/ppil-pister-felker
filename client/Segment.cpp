#include "Segment.h"

Segment::Segment(const string &couleur, Vecteur2D *pos, Vecteur2D *arrivee) :
        Forme(couleur, pos), arrivee_(arrivee) {}

Segment::~Segment() = default;

const Vecteur2D *Segment::getArrivee() const {
    return arrivee_;
}

Segment::operator string() {
    string res = "Segment:" + this->getCouleur() + ","
                 + to_string(int(this->getMargeGauche())) + ","
                 + to_string(int(this->getMargeHaut())) + ","
                 + to_string(int(arrivee_->getX())) + ","
                 + to_string(int(arrivee_->getY()));
    return res;
}
string Segment::toString() {
    string res = "Segment:" + this->getCouleur() + ","
            + to_string(int(this->getMargeGauche())) + ","
            + to_string(int(this->getMargeHaut())) + ","
            + to_string(int(arrivee_->getX())) + ","
            + to_string(int(arrivee_->getY()));
    return res;
}
string Segment::getQuery() {
    return this->toString();
}

double Segment::calculerAire() {
    Vecteur2D tmp = (*arrivee_) - (*getPos());
    return sqrt(((tmp.getX() * tmp.getX()) + (tmp.getY() * tmp.getY())));
}

void Segment::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerSegment(this);
}

void Segment::translation(Vecteur2D d) {
    Vecteur2D pos = (*getPos());
    pos = pos + d;
    setPos(new Vecteur2D(pos));
    Vecteur2D tmp = (*arrivee_);
    this->arrivee_ = new Vecteur2D((*arrivee_) + d);
}
