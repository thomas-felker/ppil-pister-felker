//
// Created by satom on 03/03/2022.
//

#ifndef CLIENT_LIBRAIRIEGRAPHIQUE_H
#define CLIENT_LIBRAIRIEGRAPHIQUE_H

class Forme;
class Segment;
class Cercle;
class Triangle;
class Polygone;

class LibrairieGraphique {
private:
public:
    LibrairieGraphique();

    virtual ~LibrairieGraphique();

    virtual void dessinerSegment(Segment * segment) = 0;
    virtual void dessinerCercle(Cercle * cercle) = 0;
    virtual void dessinerTriangle(Triangle * triangle) = 0;
    virtual void dessinerPolygone(Polygone * polygone) = 0;
};


#endif //CLIENT_LIBRAIRIEGRAPHIQUE_H
