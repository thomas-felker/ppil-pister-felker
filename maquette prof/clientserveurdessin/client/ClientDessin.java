package clientserveurdessin.client;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
/**
 * cr�e un client TCP/IP vers un serveur de dessin
 * 
 * envoie 3 requ�tes possibles :
 * 
 * ouvrir une fen�tre graphique
 * tracer un segment
 * tracer une ellipse pleine
 * 
 * protocole : Chaque requ�te est cod�e sous forme d'une seule String se terminant par le caract�re fin de ligne.
 * Sur la ligne, 2 param�tres cons�cutifs sont s�par�s par ", ".  
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
 * envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres titre, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", " 
 * 
 * */
void ouvreFen�treGraphique(String titre, int bordGauche, int bordHaut, int largeur, int hauteur)
{

String ligne;
int t [] = { bordGauche, bordHaut, largeur, hauteur};
ligne = encode (titre , t);
this.fluxSortant.println(ligne);
}

/**
    envoie sur une seule ligne les 5 param�tres au serveur.
 * Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", " 
 *  * */
void traceSegment( int x1, int y1, int x2, int y2)
{
String ligne;
int t [] = { x1, y1, x2, y2};
ligne = encode( "drawLine" , t);
this.fluxSortant.println(ligne);
}

/**
envoie sur une seule ligne les 5 param�tres au serveur.
* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", " 
*  * */
void remplitEllipse( int bordGauche, int bordHaut, int largeur, int hauteur)
{
String ligne;
int t [] = {bordGauche, bordHaut, largeur, hauteur};
ligne = encode("fillOval" , t);           
this.fluxSortant.println(ligne);
}

/**
 * Convertit tous les �l�ments du tableau a en String puis place tous les �l�ments du tableau a dans une chaine s. 
 * Entre 2 �l�ments cons�cutifs, on place ", ". Si il n'y a qu'un �l�ment, aucune ", " n'est ins�r�e
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
 * @return une String contenant tous les param�tres action, t[0], t[1], ...., t[l-1] au pr�alable convertis en String puis s�par�s par des ", ".
 * l �tant la longueur de t 
 * 
 * */
static String encode( String action, int t[])
{
return action + ", " + encode1(t);
}
}
