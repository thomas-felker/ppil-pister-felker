#pragma once
#include "Forme.h"

/**
cf. classe JAVA de m�me nom

*/
class Croix: public Forme
{
double gauche, haut,droit,bas;
public:

/**
 * @param gauche
 * @param haut
 * @param droit
 * @param bas
 */
Croix( const double gauche, const double haut, const double droit, const double bas);

void dessiner1( ClientDessin & clientDessin) const;
operator string() const;
};

