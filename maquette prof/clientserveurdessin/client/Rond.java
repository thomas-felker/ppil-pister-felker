package clientserveurdessin.client;

/**
 * Représente un cercle de centre (xCentre, yCentre) et de rayon "rayon"
 * 
 * 
 * */
public class Rond extends Forme
{
double xCentre, yCentre, rayon;




/**
 * @param xCentre
 * @param yCentre
 * @param rayon
 */
public Rond(double xCentre, double yCentre, double rayon)
{
super();
this.xCentre = xCentre;
this.yCentre = yCentre;
this.rayon = rayon;
}




@Override
public String toString()
{
return "Rond [xCentre=" + this.xCentre + ", yCentre=" + this.yCentre
        + ", rayon=" + this.rayon + "]";
}




@Override
public void dessiner1(ClientDessin clientDessin)
{

int marge = 50;
int largeur, hauteur;
largeur = hauteur = (int)(2*rayon);
int bordGauche, bordHaut;

bordGauche = (int)(xCentre - rayon);
bordHaut   = (int)(yCentre - rayon);
clientDessin.ouvreFenêtreGraphique("rond client JAVA", bordGauche-marge, bordHaut-marge, largeur+2*marge, hauteur+2*marge);

clientDessin.remplitEllipse(marge, marge, largeur, hauteur);


}

}
