//
// Created by satom on 17/03/2022.
//

#include "parserSegment.h"

parserSegment::parserSegment(parserCOR *suivant) : parserCOR(suivant) {}

bool parserSegment::saitCharger(const string &query) {
    if (query.find("Segment") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Forme *parserSegment::charger(const string &query) {
    vector<string> v = split(query, ",");
    Vecteur2D * P1 = new Vecteur2D(stod(v[1]), stod(v[2]));
    Vecteur2D * P2 = new Vecteur2D(stod(v[3]), stod(v[4]));
    vector<Vecteur2D *> points;
    points.push_back(P1);
    points.push_back(P2);
    return new Segment(v[0], points);
}
