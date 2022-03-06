#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <ostream>
#include <math.h>
#include <vector>
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
    Forme(const string &nom, const string &couleur, const vector<Vecteur2D *> &points) :
        nom_(nom), couleur_(couleur), points(points) {}

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

    const vector<Vecteur2D *> &getPoints() const {
        return points;
    }

    Vecteur2D * getPoint(int i) {
        return points[i];
    }

    virtual double calculerAire() = 0;
    virtual void dessiner(LibrairieGraphique * Librairie) = 0;

    virtual void translation(Vecteur2D * d) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] + d;
        }
    }
    virtual void translation(Vecteur2D d) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] + d;
        }
    }

    virtual void homothetie (const double k, const Vecteur2D& invariant) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] * k + invariant * (1-k);
        }
    }
    virtual void homothetie (const double k, const Vecteur2D * invariant) {
        for (int i = 0; i < points.size(); i++) {
            *points[i] = *points[i] * k + (*invariant) * (1-k);
        }
    }

    virtual void rotation (const double teta, const Vecteur2D & invariant) {
        for (int i = 0; i < points.size(); i++) {
            points[i]->setX(points[i]->rotation(teta, invariant).getX());
            points[i]->setY(points[i]->rotation(teta, invariant).getY());
        }
    }

    virtual void sauvegarder(Format * format, const string & filename) {
        format->save(string(*this),filename);
    }

    virtual void mondeEcran(const Vecteur2D & dim) {
        for (int i = 0; i < points.size(); i++) {
            if (points[i]->getX() > dim.getX()) {
                translation(-(*points[i]- Vecteur2D(dim.getX()-10, 0)));
            }
            if (points[i]->getY() > dim.getY()) {
                translation(-(*points[i]- Vecteur2D(0, dim.getY()-10)));
            }
            if (points[i]->getX() < 0) {
                translation(Vecteur2D(0,35 + dim.getY()) - points[i] );
            }
            if (points[i]->getY() < 0) {
                translation(Vecteur2D(dim.getX() + 10,0) - points[i]);
            }
        }
    }

    virtual string toString() {
        string res = nom_ + ":" + couleur_ +",";
        for (int i = 0; i < points.size(); i++) {
            res += to_string((*points[i]).getX()) + "," + to_string((*points[i]).getY());
        }
        return res;
    }
    virtual explicit operator string() {
        string res = nom_ + ":" + couleur_;
        for (int i = 0; i < points.size(); i++) {
            res += "," + to_string(int((*points[i]).getX())) + ","
                    + to_string(int((*points[i]).getY()));
        }
        return res;
    }
};