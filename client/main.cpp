//
// Created by satom on 14/02/2022.
//

#include "main.h"
#include <sstream>
#include <iostream>
#include <string>
#include "Erreur.h"
#include "client/ClientDessin.h"
#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Groupe.h"
#include "libgraphique/awt.h"
#include "sauvegarde/txt.h"
#include "sauvegarde/saves/parserCOR.h"
#include "sauvegarde/saves/parserSegment.h"
#include "sauvegarde/saves/parserPolygone.h"
#include "sauvegarde/saves/parserCercle.h"
#include "sauvegarde/saves/parserTriangle.h"
#include "sauvegarde/saves/parserGroupe.h"
#include <vector>
#include<math.h>

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
        txt * format = new txt(nullptr);

        parserCOR *parser = new parserSegment(nullptr);
        parser = new parserPolygone(parser);
        parser = new parserCercle(parser);
        parser = new parserTriangle(parser);
        parser = new parserGroupe(parser);

        double a,b,k;
        k = 25;
        a = k;
        b = k;

        // Triangle
        auto * PT1 = new Vecteur2D(a+k*1, 0*k+b);
        auto * PT2 = new Vecteur2D(a+k*4, -2*k+b);
        auto * PT3 = new Vecteur2D(a+k*4, 2*k+b);
        vector<Vecteur2D*> pointsTri;
        pointsTri.push_back(PT1);
        pointsTri.push_back(PT2);
        pointsTri.push_back(PT3);
        auto * T1 = new Triangle("green", pointsTri);
        cout << "Aire triangle : " << T1->calculerAire() << endl;

        // Cercle 1
        auto * centreCercle1 = new Vecteur2D(a+k*7, 0*k+b);
        vector<Vecteur2D *> pointsCercle1;
        pointsCercle1.push_back(centreCercle1);
        auto * C1 = new Cercle("yellow",pointsCercle1, 2*k);
        cout << "Aire du cercle 1 : " << C1->calculerAire() << endl;

        // Rectangle
        auto * a1 = new Vecteur2D(a+k*11,-1*k+b);
        auto * b1 = new Vecteur2D(a+k*15, -1*k+b);
        auto * c1 = new Vecteur2D(a+k*15, 1*k+b);
        auto * d1 = new Vecteur2D(a+k*11,1*k+b);
        vector<Vecteur2D *> pointsPoly;
        pointsPoly.push_back(a1);
        pointsPoly.push_back(b1);
        pointsPoly.push_back(c1);
        pointsPoly.push_back(d1);
        auto * R1 = new Polygone("blue",pointsPoly);
        cout << "Aire du polygone : " << R1->calculerAire() << endl;

        // Cercle 2
        auto * centreCercle2 = new Vecteur2D(a+k*17, 0*k+b);
        vector<Vecteur2D *> pointsCercle2;
        pointsCercle2.push_back(centreCercle2);
        auto * C2 = new Cercle("yellow",pointsCercle2, 1*k);
        cout << "Aire du cercle 2 : " << C2->calculerAire() << endl;

        // Groupe
        vector<Forme*> formes;
        vector<Vecteur2D*> points;
        formes.push_back(T1);
        formes.push_back(C1);
        formes.push_back(R1);
        formes.push_back(C2);
        auto * G1 = new Groupe("red", points, formes);

        // Translation
        Vecteur2D vectTransl = Vecteur2D(a+k*-4,0*k+b);
        G1->translation(vectTransl);

        // Rotation
        Vecteur2D vectRota = Vecteur2D(a+k*0,0*k+b);
        double teta = M_PI/4;
        G1->rotation(teta, vectRota);

        // Aire
        cout << "Aire du groupe = " << G1->calculerAire() << endl;

        // Dessin
        G1->dessiner(lib);

        // Sauvegarde
        G1->sauvegarder(format, "majoliefigure2");

        // Chargement
        Forme * G2 = parser->traiter("majoliefigure2");
        G2->dessiner(lib);
    }
    catch (Erreur e)
    {
        cerr << e << endl;
    }

    char ch;
    cin >> ch;
    return 0;
}