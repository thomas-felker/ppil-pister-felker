//
// Created by satom on 03/03/2022.
//

#ifndef CLIENT_AWT_H
#define CLIENT_AWT_H

#include "LibrairieGraphique.h"
#include "ClientDessin.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"


class awt : public LibrairieGraphique {
private:
    ClientDessin client;
public:
    awt(const ClientDessin &client);

    virtual ~awt();

    void dessinerSegment(Segment * segment) override;
    void dessinerCercle(Cercle *cercle) override;
    void dessinerTriangle(Triangle *triangle) override;

    void dessinerPolygone(Polygone *polygone) override;
};


#endif //CLIENT_AWT_H