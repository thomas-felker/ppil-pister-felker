//
// Created by satom on 17/03/2022.
//

#include "parserCercle.h"

parserCercle::parserCercle(parserCOR *suivant) : parserCOR(suivant) {}

bool parserCercle::saitCharger(const string &query) {
    if (query.find("Cercle") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Forme *parserCercle::charger(const string &query) {
    vector<string> v = split(query, ",");
    vector<Vecteur2D *> points;
    Vecteur2D *vect = new Vecteur2D(stod(v[1]), stod(v[2]));
    points.push_back(vect);
    return new Cercle(v[0], points, stod(v[3]));
}
