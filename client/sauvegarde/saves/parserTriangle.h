//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERTRIANGLE_H
#define CLIENT_PARSERTRIANGLE_H


#include "parserCOR.h"
#include "formes/Triangle.h"

class parserTriangle : public parserCOR {
public:
    parserTriangle(parserCOR *suivant);

    bool saitCharger(const string &query) override;

    Forme *charger(const string &query) override;
};


#endif //CLIENT_PARSERTRIANGLE_H
