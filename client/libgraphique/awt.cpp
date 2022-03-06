//
// Created by satom on 03/03/2022.
//

#include "awt.h"

awt::awt(const ClientDessin &client) : client(client) {}
awt::~awt() = default;

void awt::dessinerSegment(Segment * segment) {
    client.envoyer(string((*segment)));
}

void awt::dessinerCercle(Cercle *cercle) {
    client.envoyer(string(*cercle));
}

void awt::dessinerTriangle(Triangle *triangle) {
    client.envoyer(string(*triangle));
}

void awt::dessinerPolygone(Polygone *polygone) {
    client.envoyer(string(*polygone));
}
