package session;

import cadre.CadreDessin;
import formes.*;

import java.net.Socket;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;

public class SessionDessin extends Thread {
    Socket socket;
    BufferedReader fluxEntrant;
    CadreDessin cadre_;

    /** Crée la session de dessin avec le client distant connecté sur socket
     * @throws IOException
     **/
    public SessionDessin(Socket socket) throws IOException {
        this.socket = socket;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
    }

    /**
        @brief initialise le cadre de dessin avec les dimension du client 
     */

    public CadreDessin initCadre(String query) throws IOException, InterruptedException {
        String requete[] = query.split(":");

        String [] arguments = requete[1].split(",");
        String titre = arguments[0].trim();
        int Ox = Integer.parseInt(arguments[1].trim());
        int Oy = Integer.parseInt(arguments[2].trim());
        int largeur = Integer.parseInt(arguments[3].trim());
        int hauteur = Integer.parseInt(arguments[4].trim());

        CadreDessin cadre = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
        return cadre;
    }

    /** @brief Lancement du serveur et application du protocole 
    */


    @Override
    public void run() {
        try {
            // -- À laisser ici
            Forme forme = null;

            while (true) {
                String query = this.fluxEntrant.readLine();
                if (query != null && (!(query.replaceAll(" ", "").equalsIgnoreCase("")))) {
                    String[] args = query.split(":");
                    if (args[0].equalsIgnoreCase("Cadre")) {
                        System.out.println("Requete reçue : " + query);
                        CadreDessin cadre = initCadre(query);
                        cadre_ = cadre;
                    } else {
                        String[] querys = query.split("/");
                        for (String requete:
                                querys) {
                            System.out.println("Requete reçue : " + requete);
                            forme = new Segment(null, cadre_);
                            forme = new Cercle(forme, cadre_);
                            forme = new Triangle(forme, cadre_);
                            forme = new Polygone(forme, cadre_);
                            forme.traiter(requete.replaceAll("/", "").replaceAll(" ", ""));
                        }
                    }
                }
            }
        } catch (SocketException e) {
            System.out.println("session de dessin terminée par le client");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
