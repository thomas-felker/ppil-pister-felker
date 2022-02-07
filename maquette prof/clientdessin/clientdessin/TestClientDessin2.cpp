
/**
 * Essai du client qui envoie des formes à dessiner au serveur de dessin
 * 
 * 
 * */

#include <iostream>
#include "Forme.h"
#include "Croix.h"
#include "Rond.h"
#include "Erreur.h"

using namespace std;

int main()
{
try
{
Forme * f1, * f2;

f1 = new Croix(40, 40, 100, 100);
f2 = new Rond(300, 300, 30);

cout << "f1 = " << f1 << endl;
cout << "f2 = " << f2 << endl;

f1->dessiner();      // requête vers le serveur de dessin
f2->dessiner();      // requête vers le serveur de dessin
}
catch(Erreur e)
{
cerr << e << endl;
}
char ch;
cin >> ch;

return 0;
}