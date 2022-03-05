//
// Created by satom on 05/03/2022.
//

#ifndef CLIENT_MATRICE_H
#define CLIENT_MATRICE_H


#include <string>
#include <math.h>
using namespace std;

class Matrice {
private:
    double a,b,c,d;
public:
    Matrice(double a, double b, double c, double d);

    virtual ~Matrice();

    double getA() const;
    void setA(double a);

    double getB() const;
    void setB(double b);

    double getC() const;
    void setC(double c);

    double getD() const;
    void setD(double d);

    static Matrice creerMatRotation(double teta) {
        double x = cos(teta);
        double y = sin(teta);
        return Matrice(x, -y, y, x);
    }

    /*
    operator string() const { return "Matrice2x2:(" + to_string(a)
        + "," + to_string(b) + "," + to_string(c) + ","; +to_string(d) + ")" ;}
        */
};


#endif //CLIENT_MATRICE_H
