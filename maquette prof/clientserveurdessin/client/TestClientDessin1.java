package clientserveurdessin.client;

import java.io.IOException;
import java.net.UnknownHostException;

/**
 * Essai du client qui envoie des instructions de tracé au serveur de dessin
 * 
 * 
 * */

public class TestClientDessin1
{

/**
 * @param args
 */
public static void main(String[] args)
{
try
    {
    ClientDessin clientDessin = new ClientDessin("127.0.0.1", 8091);
    
    System.out.println("client dessin  : " + clientDessin );
    
    clientDessin.ouvreFenêtreGraphique("fenêtre ouverte par un client JAVA distant", 50, 50, 100, 100);
    clientDessin.traceSegment(10, 10, 80, 80);
    clientDessin.remplitEllipse(30 , 40, 20, 30);
    }
catch (UnknownHostException e)
    {
    // TODO Auto-generated catch block
    e.printStackTrace();
    }
catch (IOException e)
    {
    // TODO Auto-generated catch block
    e.printStackTrace();
    }

}

}
