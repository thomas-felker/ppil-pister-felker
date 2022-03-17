//
// Created by satom on 17/03/2022.
//

#include "parserGroupe.h"
#include "parserSegment.h"
#include "parserTriangle.h"
#include "parserPolygone.h"
#include "parserCercle.h"

parserGroupe::parserGroupe(parserCOR *suivant) : parserCOR(suivant) {}

bool parserGroupe::saitCharger(const string &query) {
    if (query.find("Groupe") != std::string::npos) {
        return true;
    } else {
        return false;
    }
}

Forme *parserGroupe::charger(const string &query) {
    string tmpQuery = query.substr(query.find(":") + 1);
    cout << "query = " << query << endl;
    vector<string> v = split(tmpQuery, "/");
    vector<Forme *> formes;


    parserCOR *parser = new parserSegment(nullptr);
    parser = new parserPolygone(parser);
    parser = new parserCercle(parser);
    parser = new parserTriangle(parser);


    for(int  i = 0 ; i < v.size() ; i++) {
        Forme * forme = parser->traiterQuery(v[i]);
        formes.push_back(forme);
    }
    return new Groupe(formes[0]->getCouleur(), formes);

}
