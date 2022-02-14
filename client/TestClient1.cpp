//
// Created by satom on 14/02/2022.
//

#include "TestClient1.h"

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

#pragma comment(lib, "ws2_32.lib")

int main()
{
    try
    {
        string adresseServeur = "127.0.0.1";
        int portServeurDessin = 8091;

        ClientDessin clientDessin( adresseServeur, portServeurDessin);

        string titre = "Cadre";

        int bordGauche = 300;
        int bordHaut = 400;
        int largeur = 200;
        int hauteur = 200;

        clientDessin.ouvreFenetreGraphique( titre, bordGauche, bordHaut, largeur, hauteur);

        int x1 = 180;
        int y1 = 40;
        int x2 = 40;
        int y2 = 180;

        clientDessin.traceSegment( x1, y1, x2, y2);

        bordGauche = 300;
        bordHaut = 400;
        largeur = 200;
        hauteur = 200;

        clientDessin.ouvreFenetreGraphique( titre, bordGauche, bordHaut, largeur, hauteur);

        bordGauche = 40;
        bordHaut = 100;
        largeur = 70;
        hauteur = 70;

        clientDessin.remplitEllipse( bordGauche, bordHaut, largeur, hauteur);
    }
    catch (Erreur e)
    {
        cerr << e << endl;
    }

    char ch;
    cin >> ch;
    return 0;
}



