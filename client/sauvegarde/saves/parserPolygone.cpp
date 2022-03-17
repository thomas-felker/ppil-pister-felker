//
// Created by satom on 17/03/2022.
//

#include "parserPolygone.h"

parserPolygone::parserPolygone(parserCOR *suivant) : parserCOR(suivant) {}

bool parserPolygone::saitCharger(const string &query) {
    if (query.find("Polygone") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Forme *parserPolygone::charger(const string &query) {
    vector<string> v = split(query, ",");
    vector<Vecteur2D *> points;
    for(int  i = 1 ; i < v.size() ; i= i+2) {
        Vecteur2D *vect = new Vecteur2D(stod(v[i]), stod(v[i + 1]));
        points.push_back(vect);
    }
    return new Polygone(v[0], points);
}
