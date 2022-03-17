//
// Created by satom on 17/03/2022.
//

#ifndef CLIENT_PARSERCOR_H
#define CLIENT_PARSERCOR_H

#include "formes/Forme.h"
#include "formes/Groupe.h"


class parserCOR {
private :
    parserCOR * suivant;
public:
    parserCOR(parserCOR *suivant) : suivant(suivant) {}

    parserCOR *getSuivant() const {
        return suivant;
    }

    bool aUnSuivant() const {
        return suivant != nullptr;
    }

    virtual Forme * traiter(const string & filename) {
        string tmpfile = "C:/Users/satom/Documents/GitHub/ppil-pister-felker/client/sauvegarde/saves/" +filename + ".txt";
        fstream file;
        string tmp;
        file.open(tmpfile,ios::in); //open a file to perform read operation using file object
        if (file.is_open()){   //checking whether the file is open
            while(getline(file, tmp)){  //read data from file object and put it into string.
                vector<string> v = split(tmp, ":");
                if (v[0] == "Groupe") {
                    cout << "Tentative de chargement du groupe...." << endl;
                    string tmpQuery = tmp.substr(tmp.find(":") + 1);
                    vector<string> v2 = split(tmpQuery, "/");
                    vector<Forme *> formes = *(new vector<Forme *>);
                    for(int  i = 0 ; i < v2.size() ; i++){
                        Forme * forme = traiterQuery(v2[i]);
                        formes.push_back(forme);
                        cout << "forme = " << string(*forme) << endl;
                    }
                    for (int i = 0; i< formes.size() ; i++) {
                        cout << "test" << endl;
                        cout << "forme = " << string(*formes[i]) << endl;
                    }
                    Groupe * tmp = new Groupe(formes[0]->getCouleur(), formes);
                    cout << "Groupe = " << string(*tmp) << endl;
                    return tmp;
                }
                if (saitCharger(v[0])) {
                    return charger(v[1]);
                }
                if (aUnSuivant()) {
                    return suivant->traiter(filename);
                } else {
                    Erreur("Forme inconnue");
                }
            }
            file.close();   //close the file object.
        } else {
            cout << "file not found" << endl;
        }
    }

    virtual Forme * traiterQuery(const string & query) {
        vector<string> v = split(query, ":");
        if (saitCharger(v[0])) {
            return charger(v[1]);
        }
        if (aUnSuivant()) {
            return suivant->traiterQuery(query);
        } else {
            Erreur("Forme inconnue");
        }
    }


    virtual bool saitCharger(const string & query) = 0;

    virtual Forme * charger(const string & query) = 0;

    // for string delimiter
    vector<string> split (string s, string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }


};


#endif //CLIENT_PARSERCOR_H
