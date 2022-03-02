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

    /** Crée la session de dessin avec le client distant connecté sur socket
     * @throws IOException
     **/
    public SessionDessin(Socket socket) throws IOException {
        this.socket = socket;
        this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
    }

    public CadreDessin createCadre(String query) throws IOException, InterruptedException {
        String arguments[] = query.split(",");

        String titre;
        int Ox, Oy, largeur, hauteur;

        titre = arguments[0].trim();
        Ox = Integer.parseInt(arguments[1].trim());
        Oy = Integer.parseInt(arguments[2].trim());
        largeur = Integer.parseInt(arguments[3].trim());
        hauteur = Integer.parseInt(arguments[4].trim());

        CadreDessin cadre = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
        return cadre;
    }

    @Override
    public void run() {
        try {
            Forme forme = null;
            while (true) {
                String query = this.fluxEntrant.readLine();
                if (query != null && (!(query.replaceAll(" ", "").equalsIgnoreCase("")))) {
                    String[] args = query.split(",");

                    if (args[0].equalsIgnoreCase("Cadre")) {
                        System.out.println("Requete reçue : " + query);
                        CadreDessin cadre = createCadre(query);

                        forme = new Segment(null, cadre);
                        forme = new Cercle(forme, cadre);
                        forme = new Triangle(forme, cadre);
                        forme = new Polygone(forme, cadre);
                    } else {
                        String[] argstmp = query.split("/");
                        for (String arg:
                             argstmp) {
                            String test[] = arg.split(":");
                            if ((test[0].replaceAll(" ", "").equalsIgnoreCase("Forme"))) {
                                System.out.println("Requete reçue : " + test[1]);
                                forme.traiter(test[1].replaceAll("/", "").replaceAll(" ", ""));
                            }
                        }
                        // forme.traiter(query);
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
