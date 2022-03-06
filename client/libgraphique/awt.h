//
// Created by satom on 03/03/2022.
//

#ifndef CLIENT_AWT_H
#define CLIENT_AWT_H

#include "libgraphique/LibrairieGraphique.h"
#include "client/ClientDessin.h"
#include "formes/Segment.h"
#include "formes/Cercle.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"


class awt : public LibrairieGraphique {
private:
    ClientDessin client;
public:
    explicit awt(const ClientDessin &client);

    ~awt() override;

    void dessinerSegment(Segment * segment) override;
    void dessinerCercle(Cercle *cercle) override;
    void dessinerTriangle(Triangle *triangle) override;
    void dessinerPolygone(Polygone *polygone) override;
};


#endif //CLIENT_AWT_H