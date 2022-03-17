//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERGROUPE_H
#define CLIENT_PARSERGROUPE_H

#include "formes/Groupe.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Cercle.h"
#include "parserCOR.h"

class parserGroupe : public parserCOR {
public:
    parserGroupe(parserCOR *suivant);

    bool saitCharger(const string &query) override;

    Forme *charger(const string &query) override;
};


#endif //CLIENT_PARSERGROUPE_H
