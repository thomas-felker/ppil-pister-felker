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
#include "Cercle.h"

#pragma comment(lib, "ws2_32.lib")

int main()
{
    try
    {
        string adresseServeur = "127.0.0.1";
        int portServeurDessin = 8091;

        ClientDessin clientDessin( adresseServeur, portServeurDessin);

        string titre = "Cadre";

        int margeGauche = 600;
        int margeHaut = 100;
        int largeur = 200;
        int hauteur = 200;

        clientDessin.ouvreFenetreGraphique( titre, margeGauche, margeHaut, largeur, hauteur);

        int x1 = 180;
        int y1 = 40;
        int x2 = 40;
        int y2 = 180;

        // clientDessin.traceSegment( x1, y1, x2, y2);

        margeGauche = 300;
        margeHaut = 400;
        largeur = 200;
        hauteur = 200;

        // clientDessin.ouvreFenetreGraphique( titre, margeGauche, margeHaut, largeur, hauteur);

        margeGauche = 80;
        margeHaut = 40;
        largeur = 70;
        hauteur = 70;

        // clientDessin.remplitEllipse( margeGauche, margeHaut, largeur, hauteur);
        Cercle * cercle = new Cercle(margeHaut, margeGauche, "blue", largeur, hauteur);
        ostringstream oss = cercle->getQuery();
        int r = send( clientDessin.getSock(), oss.str().c_str(), oss.str().length(), 0);             //------------------ envoi de la requête au serveur -------------------------------

        if (r == SOCKET_ERROR)
            throw Erreur("échec de l'envoi de la requête de tracé de segment");

        cout << "requête envoyée : " << oss.str() << endl;
    }
    catch (Erreur e)
    {
        cerr << e << endl;
    }

    char ch;
    cin >> ch;
    return 0;
}


