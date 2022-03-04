#include "Segment.h"

Segment::Segment(const string &couleur, const vector<Vecteur2D *> &points) :
    Forme("Segment",couleur, points) {}


double Segment::calculerAire() {
    Vecteur2D tmp = (*getPoint(1) - (*getPoint(0)));
    return sqrt(((tmp.getX() * tmp.getX()) + (tmp.getY() * tmp.getY())));
}

void Segment::dessiner(LibrairieGraphique *Librairie) {
    Librairie->dessinerSegment(this);
}