//
// Created by satom on 05/03/2022.
//

#ifndef CLIENT_TXT_H
#define CLIENT_TXT_H

#include <iostream>
#include <fstream>
#include "sauvegarde/Format.h"
#include "client/ClientDessin.h"

#if defined(_WIN16) | defined(_WIN32) | defined(_WIN64)
#define SEPERATOR "\\"
#else
#define SEPERATOR "/"
#endif

class txt : public Format{
public:
    explicit txt(Format *suivant);

    ~txt() override;

    void save(string query, string filename) override;

    void charger(ClientDessin & client, string filename) override;

    bool saitCharger(string type) override;

    operator string() override;
};


#endif //CLIENT_TXT_H
