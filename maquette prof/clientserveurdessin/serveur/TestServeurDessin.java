package clientserveurdessin.serveur;
/**
 * Serveur dessinant des sc�nes 2D en Active-Rendering sur l'�cran local. Les ordres de trac�s sont donn�s par les clients distants.
 * 
 *  Serveur multi-client
 * 
 * 
 * 
 * */

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

//import clientserveurdessin.serveur.maladroit.SessionDessin;
import clientserveurdessin.serveur.mieux.SessionDessin;

public class TestServeurDessin
{

public static void main(String[] args)
{
int portServeurDessin = 8091;   // arbitraire. N'importe quel port libre convient
try
    {
    ServerSocket serveurDessin = new ServerSocket(portServeurDessin);
    
    System.out.println("serveur de dessin pr�t, \n d�tails : "+serveurDessin);
    
    int nombreClients;
    
    nombreClients = 0;
    
    while (true)
        {
        System.out.println("serveur de dessin en attente du prochain client");
        Socket socket = serveurDessin.accept();
        ++nombreClients;
        System.out.println("nouveau client connect� n� = " + nombreClients);
        SessionDessin sessionDessin = new SessionDessin(socket);                // interlocuteur prenant en charge la session de dessin du nouveau client,
        sessionDessin.start();                                                  // il travaille dans un thread s�par�, en parall�le de l'activit� de serveurDessin
        }
    }
catch (IOException e)
    {
    
    System.err.println("Le serveur n'a pu �tre connect� sur le port d'�coute ou la connexion sur ce port a �t� rompue. \n D�tails : "+e);
    }
}
}
