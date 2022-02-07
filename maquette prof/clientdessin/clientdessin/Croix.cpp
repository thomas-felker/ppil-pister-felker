
#include <sstream>
#include "Croix.h"

/**
 * @param gauche
 * @param haut
 * @param droit
 * @param bas
 */
Croix::Croix( const double gauche, const double haut, const double droit, const double bas) : gauche(gauche), haut(haut), droit(droit), bas(bas) {}



void Croix::dessiner1( ClientDessin & clientDessin) const
{
int marge, largeur, hauteur;
largeur = (int)(droit - gauche);
hauteur = (int)(bas - haut);
marge = 50;
clientDessin.ouvreFenetreGraphique("croix client C++", (int)gauche - marge, (int)haut - marge, largeur + 2*marge, hauteur + 2*marge);

clientDessin.traceSegment(marge,         marge, marge+largeur, marge+hauteur);
clientDessin.traceSegment(marge, marge+hauteur, marge+largeur,         marge);

}

Croix::operator string() const
{
ostringstream oss;

oss << "Croix : "<< "gauche = "<< gauche << ", haut = "<< haut << ", droit = " << droit <<  ", bas = " << bas;

return oss.str();
}
