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

void txt::charger(ClientDessin & client, string filename) {
    cout << "file : "<< filename << endl;
    string res, tp;
    fstream file;
    file.open(filename,ios::in); //open a file to perform read operation using file object
    if (file.is_open()){   //checking whether the file is open
        while(getline(file, tp)){  //read data from file object and put it into string.
            cout << "res : "<< res << endl;
            res+=tp;   //print the data of the string
        }
        file.close();   //close the file object.
    }
    cout << "res : "<< res << endl;
    client.envoyer(res);
}

bool txt::saitCharger(string type) {
    return (type == "txt");
}

txt::operator string() {
    return "txt";
}

