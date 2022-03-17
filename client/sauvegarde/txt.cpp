//
// Created by satom on 05/03/2022.
//

#include "txt.h"

txt::txt(Format *suivant) : Format(suivant) {}

txt::~txt() = default;

void txt::save(string query, string filename) {
    std::ofstream o("../sauvegarde/saves/" + filename + ".txt");
    o << query << std::endl;
    o.close();
}


txt::operator string() {
    return "txt";
}

