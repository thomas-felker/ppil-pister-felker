//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERSEGMENT_H
#define CLIENT_PARSERSEGMENT_H


#include "parserCOR.h"
#include "formes/Segment.h"

class parserSegment : public parserCOR {
public :
    parserSegment(parserCOR *suivant);

    bool saitCharger(const string &query) override;

    Forme *charger(const string &query) override;
};


#endif //CLIENT_PARSERSEGMENT_H
