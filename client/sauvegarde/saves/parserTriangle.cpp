//
// Created by satom on 17/03/2022.
//

#include "parserTriangle.h"

parserTriangle::parserTriangle(parserCOR *suivant) : parserCOR(suivant) {}

bool parserTriangle::saitCharger(const string &query) {
    if (query.find("Triangle") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Forme *parserTriangle::charger(const string &query) {
    vector<string> v = split(query, ",");
    vector<Vecteur2D *> points;
    for(int  i = 1 ; i < v.size() ; i+2) {
        Vecteur2D *vect = new Vecteur2D(stod(v[i]), stod(v[i + 1]));
        points.push_back(vect);
    }
    return new Triangle(v[0], points);
}
