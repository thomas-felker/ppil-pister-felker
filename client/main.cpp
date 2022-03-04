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
#include <vector>

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
        auto * dim = new Vecteur2D(900,900);
        clientDessin.initCadre(marge, dim);

        awt * lib = new awt(clientDessin);


        // ---------------------------------------------------
        // Polygone
        auto * a1 = new Vecteur2D(40,40);
        auto * b1 = new Vecteur2D(90, 40);
        auto * c1 = new Vecteur2D(90, 90);
        auto * d1 = new Vecteur2D(40,90);

        vector<Vecteur2D *> pointsPoly;
        pointsPoly.push_back(a1);
        pointsPoly.push_back(b1);
        pointsPoly.push_back(c1);
        pointsPoly.push_back(d1);
        auto * polygone = new Polygone("blue",pointsPoly);
        cout << "Aire du polygone = " << polygone->calculerAire() << endl;
        // Vecteur2D trPoly = Vecteur2D(0,100);
        Vecteur2D homoPoly = Vecteur2D(0,0);
        // polygone->translation(trPoly);
        polygone->homothetie(2, homoPoly);
        polygone->dessiner(lib);

        /*
        // ---------------------------------------------------
        // Cercle
        auto * centreCercle = new Vecteur2D(150, 75);
        vector<Vecteur2D *> pointsCercle;
        pointsCercle.push_back(centreCercle);
        auto * cercle = new Cercle("green",pointsCercle, 50);
        cout << "Aire du cercle = " << cercle->calculerAire() << endl;
        // Vecteur2D trCercle = Vecteur2D(0,50);
        // cercle->translation(trCercle);
        // cercle->dessiner(lib);

        // ---------------------------------------------------
        // Triangle
        auto * a2 = new Vecteur2D(40, 110);
        auto * b2 = new Vecteur2D(40, 160);
        auto * c2 = new Vecteur2D(90, 110);
        vector<Vecteur2D*> pointsTri;
        pointsTri.push_back(a2);
        pointsTri.push_back(b2);
        pointsTri.push_back(c2);
        auto * triangle = new Triangle("yellow", pointsTri);
        cout << "Aire du triangle = " << triangle->calculerAire() << endl;
        // Vecteur2D trTriangle = Vecteur2D(100, -50);
        // triangle->translation(trTriangle);
        // triangle->dessiner(lib);


        // ---------------------------------------------------
        // Segment
        auto * dep = new Vecteur2D(50,50);
        auto * arr = new Vecteur2D(100, 100);
        vector<Vecteur2D *> pointsSeg;
        pointsSeg.push_back(dep);
        pointsSeg.push_back(arr);
        auto * segment = new Segment("black", pointsSeg);
        cout << "Longueur / aire du segment = " << segment->calculerAire() << endl;
        auto* transSeg = new Vecteur2D(0,150);
        segment->translation(transSeg);
        // segment->dessiner(lib);

        // ---------------------------------------------------
        // Groupe
        vector<Forme*> formes;
        vector<Vecteur2D*> points;
        formes.push_back(polygone);
        formes.push_back(cercle);
        formes.push_back(triangle);
        formes.push_back(segment);
        auto * groupe = new Groupe("red", points, formes);

        Vecteur2D trGroupe = Vecteur2D(50,50);
        double aireGr = groupe->calculerAire();
        cout << "Aire du groupe = " << aireGr << endl;
        // groupe->translation(trGroupe);
        groupe->dessiner(lib);
         */



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