package clientserveurdessin.serveur.maladroit;

/**
 * repr�sente la session de dessin entreprise par un client distant.
 * 
 * Effectue principalement les op�rations suivantes :
 * 
 * ouvre une fen�tre awt (Frame) pour dessiner dessus (les coordonn�es de la fen�tre sont indiqu�es par le client).
 * puis ex�cute sur la fen�tre ouverte tous les ordres de trac� du client distant.
 * 
 * doit �tre am�lior�e : doit fonctionner dans un thread s�par� du thread principal. cf. classe Thread et/ou interface Runnable
 * 
 * pourrait �tre am�lior�e en g�rant les WindowEvent pour garantir la restauration du dessin (comme ce que fait repaint()) :
 * La classe pourrait donc �tre am�lior�e en h�ritant de WindowAdapter ou de WindowListener
 * 
 * */
import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;

public class SessionDessin 
{
BufferedReader fluxEntrant;     // flux entrant pour recevoir les requ�tes du client


/**
 * cr�e la session de dessin avec le client distant connect� sur socket
 * @throws IOException 
 * 
 * */
public SessionDessin(Socket socket) throws IOException
{
this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
}

public void start()
{
String requ�te;

try
    {
    requ�te = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonn�es Ox, Oy, largeur et hauteur de la fen�tre, les arguments sont s�par�s par des ","
    System.out.println("requ�te re�ue : " + requ�te);
    String arguments[] = requ�te.split(",");        // redondance de code � �liminer. Il faut �crire la m�thode d�coder() r�ciproque de la m�thode encoder() de ClientDessin
    
    String titre;
    int Ox, Oy, largeur, hauteur;
    
    titre = arguments[0].trim();
    Ox = Integer.parseInt(arguments[1].trim());         // redondance de code � �liminer pour 8 lignes !!!! cf. lignes suivantes
    Oy = Integer.parseInt(arguments[2].trim());
    largeur = Integer.parseInt(arguments[3].trim());
    hauteur = Integer.parseInt(arguments[4].trim());
    
    CadreDessin cadreDessin = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
   
    while (true)
        {
        requ�te = this.fluxEntrant.readLine();  // lit l'instruction de trac� et les 4 param�tres entiers du trac�, les arguments sont s�par�s par des ","
        
        System.out.println("requ�te re�ue : " + requ�te);
        arguments = requ�te.split(",");                     // redondance de code � �liminer
    
        String op�ration;
        int x1, y1, x2, y2;
    
        op�ration = arguments[0].trim();
        x1 = Integer.parseInt(arguments[1].trim());
        y1 = Integer.parseInt(arguments[2].trim());
        x2 = Integer.parseInt(arguments[3].trim());
        y2 = Integer.parseInt(arguments[4].trim());
    
        if (op�ration.equalsIgnoreCase("drawLine"))             // if-else � �liminer par l'utilisation du Design Pattern "Chain Of Responsibility" 
           cadreDessin.graphics.drawLine(x1,y1,x2,y2);
           
        else
            if (op�ration.equalsIgnoreCase("fillOval"))
               cadreDessin.graphics.fillOval(x1,y1,x2,y2);
               
            else
                {
                /* Op�ration non reconnue, on ne fait rien */
                }
        cadreDessin.getBufferStrategy().show();
        } // while
    }

catch (SocketException e)
    {
    System.out.println("session de dessin termin�e par le client");
    }
catch (NumberFormatException e)
    {
    e.printStackTrace();
    }
catch (IOException e)
    {
    e.printStackTrace();
    }
catch (InterruptedException e)
    {
    e.printStackTrace();
    }
}

}
