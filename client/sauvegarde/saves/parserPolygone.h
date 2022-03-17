//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERPOLYGONE_H
#define CLIENT_PARSERPOLYGONE_H

#include "formes/Polygone.h"
#include "parserCOR.h"

class parserPolygone : public parserCOR {
public:
    parserPolygone(parserCOR *suivant);

    bool saitCharger(const string &query) override;

    Forme *charger(const string &query) override;

};


#endif //CLIENT_PARSERPOLYGONE_H
