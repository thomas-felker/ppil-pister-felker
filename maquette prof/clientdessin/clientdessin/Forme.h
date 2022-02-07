#pragma once

#include <iostream>
#include <string>
#include "ClientDessin.h"

using namespace std;

/**
 * Hiérarchie simplifiée de formes en 2D
 * 
 * */
class Forme
{
public:

void dessiner() const;

virtual  void dessiner1( ClientDessin & clientDessin) const = 0;

virtual operator string () const = 0;

};

ostream & operator << (ostream & os, const Forme * forme);