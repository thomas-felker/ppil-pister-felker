package clientserveurdessin.client;

/**
 * Essai du client qui envoie des formes à dessiner au serveur de dessin
 * 
 * 
 * */

public class TestClientDessin2
{

public static void main(String[] args)
{

Forme f1, f2;

f1 = new Croix(40, 40, 100, 100);
f2 = new Rond(300, 300, 30);

f1.dessiner();      // requête vers le serveur de dessin
f2.dessiner();      // requête vers le serveur de dessin
    
}
}
