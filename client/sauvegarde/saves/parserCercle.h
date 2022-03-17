//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERCERCLE_H
#define CLIENT_PARSERCERCLE_H

#include "formes/Cercle.h"
#include "parserCOR.h"

class parserCercle : public parserCOR{
public:
    parserCercle(parserCOR *suivant);

    bool saitCharger(const string &query) override;

    Forme *charger(const string &query) override;

};


#endif //CLIENT_PARSERCERCLE_H
