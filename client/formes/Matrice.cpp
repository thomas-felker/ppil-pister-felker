//
// Created by satom on 05/03/2022.
//

#include "Matrice.h"

Matrice::Matrice(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

Matrice::~Matrice() {

}

double Matrice::getA() const {
    return a;
}

void Matrice::setA(double a) {
    Matrice::a = a;
}

double Matrice::getB() const {
    return b;
}

void Matrice::setB(double b) {
    Matrice::b = b;
}

double Matrice::getC() const {
    return c;
}

void Matrice::setC(double c) {
    Matrice::c = c;
}

double Matrice::getD() const {
    return d;
}

void Matrice::setD(double d) {
    Matrice::d = d;
}
