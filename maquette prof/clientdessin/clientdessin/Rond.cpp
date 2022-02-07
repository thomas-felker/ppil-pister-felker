#include <sstream>
#include "Rond.h"

/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
Rond::Rond( const double xCentre, const double yCentre, const double rayon) : xCentre (xCentre), yCentre (yCentre), rayon (rayon) {}


void Rond::dessiner1( ClientDessin & clientDessin) const
{

int marge = 50;
int largeur, hauteur;
largeur = hauteur = (int)(2*rayon);
int bordGauche, bordHaut;

bordGauche = (int)(xCentre - rayon);
bordHaut   = (int)(yCentre - rayon);
clientDessin.ouvreFenetreGraphique("rond client C++", bordGauche-marge, bordHaut-marge, largeur+2*marge, hauteur+2*marge);

clientDessin.remplitEllipse(marge, marge, largeur, hauteur);

}

Rond::operator string() const
{
ostringstream oss;

oss << "Rond : "<<"xCentre = " << xCentre << ", yCentre = " << yCentre <<", rayon = " << rayon;

return oss.str();
}
