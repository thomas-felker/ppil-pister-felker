//
// Created by satom on 14/02/2022.
//

#include "main.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Erreur.h"
#include "ClientDessin.h"
#include "Cercle.h"
#include "Segment.h"
#include "Triangle.h"
#include "Groupe.h"
#include "awt.h"

/*
 * Main.cpp
 *
 *  teste les fonctionnalités de la classe ClientDessin, à savoir :
 *
 *  1) envoyer une requête de création de fenêtre graphique nue titrée
 *  2) envoyer une requête de tracé de segment
 *  3) envoyer une requête de dessin d'ellipse pleine
 *
 */

#pragma comment(lib, "ws2_32.lib")

int main()
{
    try
    {
        string adresseServeur = "127.0.0.1";
        int portServeurDessin = 8091;
        ClientDessin clientDessin( adresseServeur, portServeurDessin);

        auto * marge = new Vecteur2D(100,100);
        auto * dim = new Vecteur2D(300,300);
        clientDessin.initCadre(marge, dim);

        awt * lib = new awt(clientDessin);

        // ---------------------------------------------------
        // Polygone
        auto * pos1 = new Vecteur2D(40,40);
        auto * a1 = new Vecteur2D(90, 40);
        auto * b1 = new Vecteur2D(90, 90);
        auto * c1 = new Vecteur2D(40,90);

        list<Vecteur2D *> points;
        points.push_back(a1);
        points.push_back(b1);
        points.push_back(c1);
        auto * polygone = new Polygone("blue",pos1,points);
        cout << "Aire du cercle = " << polygone->calculerAire() << endl;
        // Vecteur2D trPoly = Vecteur2D(0,100);
        // polygone->translation(trPoly);

        // ---------------------------------------------------
        // Cercle
        auto * pos2 = new Vecteur2D(150, 90);
        auto * cercle = new Cercle("green",pos2, 50);
        cout << "Aire du cercle = " << cercle->calculerAire() << endl;
        // Vecteur2D trCercle = Vecteur2D(0,50);
        // cercle->translation(trCercle);

        // ---------------------------------------------------
        // Triangle
        auto * pos3 = new Vecteur2D(40, 110);
        auto * a2 = new Vecteur2D(40, 160);
        auto * b2 = new Vecteur2D(90, 110);
        auto * triangle = new Triangle("yellow", pos3, a2, b2);
        cout << "Aire du triangle = " << triangle->calculerAire() << endl;
        // Vecteur2D trTriangle = Vecteur2D(100, -50);
        // triangle->translation(trTriangle);

        // ---------------------------------------------------
        // Segment
        auto * pos4 = new Vecteur2D(40,200);
        auto * arr = new Vecteur2D(90, 140);
        auto * segment = new Segment("black", pos4, arr);
        cout << "Longueur / aire du segment = " << segment->calculerAire() << endl;

        // ---------------------------------------------------
        // Groupe
        list<Forme*> list;
        list.push_back(polygone);
        list.push_back(cercle);
        list.push_back(triangle);
        list.push_back(segment);
        auto * groupe = new Groupe("red", list);

        Vecteur2D trGroupe = Vecteur2D(50,50);
        double aireGr = groupe->calculerAire();
        cout << "Aire du groupe = " << aireGr << endl;
        // groupe->translation(trGroupe);
        groupe->dessiner(lib);


        /**
         * Requête ouverture fenêtre graphique :
         * oss << titre << ", " << bordGauche << ", "
         * << bordHaut << ", " << largeur << ", "
         * << hauteur << "\r\n";
         * ex : Cadre, 600, 100, 500, 500
         */

        /**
         * Requête de dessin :
         * ex : Forme:Cercle,red,50,50,20,20
         * Segment * segment = new Segment("red", depart, arrivee_);
         *     ostringstream oss2 = segment->getQuery();
         */

        /*
        //fprintf
        char requete[200] = "";
        string oldrequete;
        bool continuer;

        do {
            oldrequete = string(requete);

            cout << "requete :";
            cin >> requete;

            continuer = (strcmp(requete, "quitter") != 0);

            if (continuer) {
                strcat_s(requete, "\r \n");

                int r = send( clientDessin.getSock(), requete, strlen(requete), 0);
                if (r == SOCKET_ERROR)
                    throw Erreur("échec de l'envoi de la requête");
            }

        } while (continuer);
         */
    }
    catch (Erreur e)
    {
        cerr << e << endl;
    }

    char ch;
    cin >> ch;
    return 0;
}