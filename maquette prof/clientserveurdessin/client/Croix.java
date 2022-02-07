package clientserveurdessin.client;


/**
 * Repr�sente une croix. Celle-ci est d�finie par les diagonales du carr� de sommets (gauche, haut), (gauche, bas), (droit, bas) et (droit, haut) 
 * 
 * 
 * */
public class Croix extends Forme
{
double gauche, haut,droit,bas; 


/**
 * @param gauche
 * @param haut
 * @param droit
 * @param bas
 */
public Croix(double gauche, double haut, double droit, double bas)
{
super();
this.gauche = gauche;
this.haut = haut;
this.droit = droit;
this.bas = bas;
}


@Override
public String toString()
{
return "Croix [gauche=" + this.gauche + ", haut=" + this.haut + ", droit="
        + this.droit + ", bas=" + this.bas + "]";
}


@Override
public void dessiner1(ClientDessin clientDessin)
{

int marge, largeur, hauteur;
largeur = (int)(droit - gauche);
hauteur = (int)(bas - haut);
marge = 50;
clientDessin.ouvreFen�treGraphique("croix client JAVA", (int)gauche - marge, (int)haut - marge, largeur + 2*marge, hauteur + 2*marge);

clientDessin.traceSegment(marge,         marge, marge+largeur, marge+hauteur);
clientDessin.traceSegment(marge, marge+hauteur, marge+largeur,         marge);

}

}
