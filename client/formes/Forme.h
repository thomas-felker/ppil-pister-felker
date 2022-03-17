#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Vecteur2D.h"
#include "libgraphique/LibrairieGraphique.h"
#include "sauvegarde/Format.h"

using namespace std;


class Forme {
private :
    string nom_, couleur_;
    bool inGroup = false;
    vector<Vecteur2D *> points;

public :

    /**
     * 
     * @brief constructeur 
     * 
     * */
    Forme(const string &nom, const string &couleur, const vector<Vecteur2D *> &points) :
        nom_(nom), couleur_(couleur), points(points) {}
/**
     * 
     * @brief destructeur 
     * 
     * */
    virtual ~Forme() = default;

    const string &getNom() const {
        return nom_;
    }
    void setNom(const string &nom) {
        nom_ = nom;
    }

    const string &getCouleur() const {
        return couleur_;
    }
    void setCouleur(const string &couleur) {
        couleur_ = couleur;
    }

    /**
     * 
     * @brief retourne les différentes coordonnée de la forme  
     * 
     * */

    const vector<Vecteur2D *> &getPoints() const {
        return points;
    }

    /**
     * 
     * @brief retourne une coordonnée de la forme  
     * 
     * */
    Vecteur2D * getPoint(int i) {
        return points[i];
    }

    /**
     * 
     * @brief calcule l'air de la forme géométrique  
     * 
     * */
    virtual double calculerAire() = 0;

    /**
     * 
     * @brief méthode permettant de dessiner la forme via la librairie  
     * 
     * */
    virtual void dessiner(LibrairieGraphique * Librairie) = 0;


/**
     * 
     * @brief opération de translation d'une forme  
     * 
     * */
    virtual void translation(Vecteur2D * d) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] + d;
        }
    }
    /**
     * 
     * @brief opération de translation d'une forme  
     * 
     * */
    virtual void translation(Vecteur2D d) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] + d;
        }
    }


    /**
     * 
     * @brief opération d'homothetie d'une forme   
     * 
     * */
    virtual void homothetie (const double k, const Vecteur2D& invariant) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = points[i]->homotetie(k, invariant);
        }
    }

     /**
     * 
     * @brief opération d'homothetie d'une forme   
     * 
     * */
    virtual void homothetie (const double k, const Vecteur2D * invariant) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = points[i]->homotetie(k, *invariant);
        }
    }


     /**
     * 
     * @brief opération rotation d'une forme   
     * 
     * */
    virtual void rotation (const double teta, const Vecteur2D & invariant) {
        for (int i = 0; i < points.size(); i++) {
            points[i]->setX(points[i]->rotation(teta, invariant).getX());
            points[i]->setY(points[i]->rotation(teta, invariant).getY());
        }
    }


    /**
     * 
     * @brief Permet de sauvegarder la forme géométrique    
     * 
     * */
    virtual void sauvegarder(Format * format, const string & filename) {
        format->save(string(*this),filename);
    }

    /**
     * 
     * @brief passage des coordonnées en monde écran   
     * 
     * */

    virtual void mondeEcran(const Vecteur2D & dim) {
        // Initialisation de P1, P2, P1', P2'
        Vecteur2D P1 = Vecteur2D(0,0);
        Vecteur2D P2 = dim;
        Vecteur2D P1_ = Vecteur2D(0,dim.getY());
        Vecteur2D P2_ = Vecteur2D(dim.getX(), 0);

        Vecteur2D C = Vecteur2D((P1.getX()+P2.getX())/2, (P1.getY()+P2.getY())/2);
        Vecteur2D C_ = Vecteur2D((P1_.getX()+P2_.getX())/2, (P1_.getY()+P2_.getY())/2);

        int eps1, eps2;
        double lambda, a, b;

        lambda = min( (abs(P2_.getX() - P1_.getX()) / abs( P2.getX() - P1.getX())),
                      abs(P2_.getY() - P1_.getY()) / abs(P2.getY() - P1.getY()));

        if ((P2.getX() - P1.getX() < 0  && P2_.getX() - P1_.getX() < 0) ||
                (P2.getX() - P1.getX() > 0  && P2_.getX() - P1_.getX() > 0)) {
            eps1 = 1;
        } else {
            eps1 = -1;
        }

        if ((P2.getY() - P1.getY() < 0  && P2_.getY() - P1_.getY() < 0) ||
            (P2.getY() - P1.getY() > 0  && P2_.getY() - P1_.getY() > 0)) {
            eps2 = 1;
        } else {
            eps2 = -1;
        }

        a = C_.getX() - lambda * C.getX();
        b = C_.getY() - lambda * C.getY();


        cout << "P1 = " << string(P1) << endl;
        cout << "P2 = " << string(P2) << endl;
        cout << "P1_ = " << string(P1_) << endl;
        cout << "P2_ = " << string(P2_) << endl;
        cout << "C = " << string(C) << endl;
        cout << "C_ = " << string(C_) << endl;
        cout << "eps1 = " << to_string(eps1) << ", eps2 = " << to_string(eps2)
            << ", lambda = " << to_string(lambda) << endl;
        cout <<  "a = " << to_string(a) << ", b = " << to_string(b) << endl;


        Vecteur2D botLeft = getBottomLeft();
        Vecteur2D topRight = getTopRight();


        // if (topRight.getX() < 0) rotation(2*M_PI, Vecteur2D(0, topRight.getY()));

        /*
        if (topRight.getY() > dim.getY()) rotation(M_PI/2, Vecteur2D(topRight.getX(), dim.getY()));
        if (botLeft.getY() < 0) rotation(3*M_PI/2, Vecteur2D(botLeft.getX(), 0));
        if (botLeft.getX() > dim.getX()) rotation(M_PI, Vecteur2D(dim.getX(), botLeft.getY()));
        */

        for (int i = 0; i < points.size(); i++) {
            cout << "old Point = " << string(*points[i]) << endl;
            points[i]->setX(lambda * eps1 * points[i]->getX() + a);
            points[i]->setY(lambda * eps2 * points[i]->getY() + b);
            cout << "new Point = " << string(*points[i]) << endl;
        }
    }

    Vecteur2D getBottomLeft() {
        double X = points[0]->getX();
        double Y = points[0]->getY();
        for (int i = 0; i < points.size(); i++) {
            if (points[i]->getX() < X) {
                X = points[i]->getX();
            }
            if (points[i]->getY() < Y) {
                Y = points[i]->getY();
            }
        }
        return Vecteur2D(X,Y);
    }

    Vecteur2D getTopRight() {
        double X = points[0]->getX();
        double Y = points[0]->getY();
        for (int i = 0; i < points.size(); i++) {
            if (points[i]->getX() > X) {
                X = points[i]->getX();
            }
            if (points[i]->getY() > Y) {
                Y = points[i]->getY();
            }
        }
        return Vecteur2D(X,Y);
    }

    virtual string toString() {
        string res = nom_ + ":" + couleur_ +",";
        for (int i = 0; i < points.size(); i++) {
            res += to_string((*points[i]).getX()) + "," + to_string((*points[i]).getY());
        }
        return res;
    }

    /**
     * 
     * @brief opérateur string permettant de convertir l'objet en un string au format de notre requete utilisé
     * par notre protocole    
     * 
     * */

    virtual explicit operator string() {
        string res = nom_ + ":" + couleur_;
        for (int i = 0; i < points.size(); i++) {
            res += "," + to_string(int((*points[i]).getX())) + ","
                    + to_string(int((*points[i]).getY()));
        }
        return res;
    }

};