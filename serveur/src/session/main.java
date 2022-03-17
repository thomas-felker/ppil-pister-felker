package session;


import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;


public class main
{

    public static void main(String[] args)
    {
        try {
            int portServeurDessin = 8091;
            {
                ServerSocket serveurDessin = new ServerSocket(portServeurDessin);

                System.out.println("serveur de dessin prêt, \n détails : " + serveurDessin);

                int nombreClients;

                nombreClients = 0;

                while (true) {
                    System.out.println("serveur de dessin en attente du prochain client");
                    Socket socket = serveurDessin.accept();
                    ++nombreClients;
                    System.out.println("nouveau client connecté n° = " + nombreClients);
                    SessionDessin sessionDessin = new SessionDessin(socket);
                    sessionDessin.start();
                }
            }
        }
        catch (IOException e)
        {

            System.err.println("Le serveur n'a pu être connecté sur le port d'écoute ou la connexion sur ce port a été rompue. \n Détails : "+e);
        }
    }
}
