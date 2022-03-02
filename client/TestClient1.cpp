//
// Created by satom on 14/02/2022.
//

#include "TestClient1.h"
#include <sstream>

/*
 * TestClientDessin1.cpp
 *
 *  Created on: 26 août 2014
 *      Author: Dominique
 *
 *
 *  teste les fonctionnalités de la classe ClientDessin, à savoir :
 *
 *  1) envoyer une requête de création de fenêtre graphique nue titrée
 *  2) envoyer une requête de tracé de segment
 *  3) envoyer une requête de dessin d'ellipse pleine
 *
 */
#include <iostream>
#include <string>
#include "Erreur.h"
#include "ClientDessin.h"
#include "Cercle.h"
#include "Segment.h"

#pragma comment(lib, "ws2_32.lib")

int main()
{
    try
    {
        string adresseServeur = "127.0.0.1";
        int portServeurDessin = 8091;

        ClientDessin clientDessin( adresseServeur, portServeurDessin);

        /*
        string titre = "Cadre";
        int margeGauche = 600;
        int margeHaut = 100;
        int largeur = 500;
        int hauteur = 500;
        clientDessin.ouvreFenetreGraphique( titre, margeGauche, margeHaut, largeur, hauteur);
        */

        /*
        Vecteur2D * poscercle = new Vecteur2D(100, 100);
        Vecteur2D * dimcercle = new Vecteur2D(30,30);
        Cercle * cercle = new Cercle("green", poscercle, dimcercle);
        ostringstream oss1 = cercle->getQuery();

        Vecteur2D * depart = new Vecteur2D(10,10);
        Vecteur2D *  arrivee = new Vecteur2D(40,40);

        Segment * segment = new Segment("red", depart, arrivee);
        ostringstream oss2 = segment->getQuery();
        ostringstream oss;
        oss << oss1.str() << "/" <<  oss2.str() << "\r\n";
        ostringstream oss3;
        oss3 << "Forme :Triangle, red, 20, 30, 50, 60, 80, 60 \r \n";

        int r = send( clientDessin.getSock(), oss3.str().c_str(), oss.str().length(), 0);
        if (r == SOCKET_ERROR)
            throw Erreur("échec de l'envoi de la requête de tracé de segment");

        cout << "Requete envoyee : " << oss3.str() << endl;
         */

        /**
         * Requête ouverture fenêtre graphique :
         * oss << titre << ", " << bordGauche << ", "
         * << bordHaut << ", " << largeur << ", "
         * << hauteur << "\r\n";
         * ex : Cadre, 600, 100, 500, 500
         */
        // Forme:Triangle,10,40,10,100,100,40
        char requete[200];
        bool continuer;
        do {
            cout << "requete :";
            cin >> requete;
            continuer = (strcmp(requete, "quitter") != 0);
            cout << to_string(continuer) << "\n";

            if (continuer) {
                strcat_s(requete, "\r \n");
                int r = send( clientDessin.getSock(), requete, strlen(requete), 0);             //------------------ envoi de la requête au serveur -------------------------------

                if (r == SOCKET_ERROR)
                    throw Erreur("échec de l'envoi de la requête");
            }
        } while (continuer);
    }
    catch (Erreur e)
    {
        cerr << e << endl;
    }

    char ch;
    cin >> ch;
    return 0;
}



