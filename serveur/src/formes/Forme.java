package formes;
import cadre.CadreDessin;

import exceptions.FormeManquanteException;

public abstract class Forme {
    private Forme suivant = null;
    public CadreDessin cadre;
    private Vecteur2D position;
    private Couleur color;
    public String args[];
    public String test[];


    /**
        @brief Constructeur 
     */

    public Forme(Forme suivant, CadreDessin cadre) {
        this.suivant = suivant;
        this.cadre = cadre;
        position = new Vecteur2D(0, 0);
        color = new Couleur();
    }

    public Vecteur2D getPosition() {
        return position;
    }
    public void setPosition(Vecteur2D position) {
        this.position = position;
    }

    public Couleur getCouleur() {
        return color;
    }
    public void setColor(Couleur color) {
        this.color = color;
    }

    
        /**
        @brief Méthode qui applique le pattern COR à une requete 
        si une des classes hériter du COR sait la traiter alors la requete est traiter sinon
        il y'a erreur   
        */

    public void traiter(String query) throws Exception {
        if (saitDessiner(query)){
            dessiner(query);
        } else if (aUnSuivant())  {
            getSuivant().traiter(query);
        } else {
            throw new FormeManquanteException();
        }
    }

    /**
     @brief retourne la prochaine classe hérité du COR pour traiter la demande 
     */
    private Forme getSuivant() { return suivant; }
    /**
     @brief Vérifie si il y'a une prochaine classe hérité du COR pour traiter la demande  
    */
    private boolean aUnSuivant() { return suivant != null; }

    
    /**
     @brief Dessine la forme demander par le client sur le cadre de dessin 
     */
    public abstract void dessiner(String query) throws Exception;

    /**
     @brief Regarde si le COR sait comment dessiner la forme demander par le client 
    */
    public abstract boolean saitDessiner(String query);
}
