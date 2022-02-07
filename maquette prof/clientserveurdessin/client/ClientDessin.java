package clientserveurdessin.client;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
/**
 * crée un client TCP/IP vers un serveur de dessin
 * 
 * envoie 3 requêtes possibles :
 * 
 * ouvrir une fenêtre graphique
 * tracer un segment
 * tracer une ellipse pleine
 * 
 * protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
 * Sur la ligne, 2 paramètres consécutifs sont séparés par ", ".  
 * 
 * */
public class ClientDessin
{
Socket socket;
PrintStream fluxSortant;

public ClientDessin(String adresseServeurDessin, int portServeurDessin) throws UnknownHostException, IOException
{
this.socket = new Socket(adresseServeurDessin, portServeurDessin);
this.fluxSortant = new PrintStream(socket.getOutputStream());
}



@Override
public String toString()
{
return "ClientDessin [socket=" + this.socket + ", fluxSortant="
        + this.fluxSortant + "]";
}



/**
 * envoie sur une seule ligne les 5 paramètres au serveur.
 * Les 5 paramètres titre, ... , hauteur sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", " 
 * 
 * */
void ouvreFenêtreGraphique(String titre, int bordGauche, int bordHaut, int largeur, int hauteur)
{

String ligne;
int t [] = { bordGauche, bordHaut, largeur, hauteur};
ligne = encode (titre , t);
this.fluxSortant.println(ligne);
}

/**
    envoie sur une seule ligne les 5 paramètres au serveur.
 * Les 5 paramètres drawLine, ... , y2 sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", " 
 *  * */
void traceSegment( int x1, int y1, int x2, int y2)
{
String ligne;
int t [] = { x1, y1, x2, y2};
ligne = encode( "drawLine" , t);
this.fluxSortant.println(ligne);
}

/**
envoie sur une seule ligne les 5 paramètres au serveur.
* Les 5 paramètres fillOval, ... , hauteur sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", " 
*  * */
void remplitEllipse( int bordGauche, int bordHaut, int largeur, int hauteur)
{
String ligne;
int t [] = {bordGauche, bordHaut, largeur, hauteur};
ligne = encode("fillOval" , t);           
this.fluxSortant.println(ligne);
}

/**
 * Convertit tous les éléments du tableau a en String puis place tous les éléments du tableau a dans une chaine s. 
 * Entre 2 éléments consécutifs, on place ", ". Si il n'y a qu'un élément, aucune ", " n'est insérée
 * @return s. renvoie "" si a est vide 
 * */
static String encode1(int [] a)
{

if (a.length == 0)
    return "";
else
    {
    int i;
    String s;
    
    s = Integer.toString(a[0]);
    
    for (i = 1; i < a.length; ++i)
        s += ", "+a[i];
    
    return s;
    }   // else
}       // encode

/**
 * @return une String contenant tous les paramètres action, t[0], t[1], ...., t[l-1] au préalable convertis en String puis séparés par des ", ".
 * l étant la longueur de t 
 * 
 * */
static String encode( String action, int t[])
{
return action + ", " + encode1(t);
}
}
