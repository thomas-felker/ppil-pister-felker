#pragma once
#include "Forme.h"
/**
 * Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
 * 
 * 
 * */
class Rond :public Forme
{
double xCentre, yCentre, rayon;
public:
/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
Rond( const double xCentre,  const double yCentre,  const double rayon);

void dessiner1( ClientDessin & clientDessin) const;

operator string() const;
};
