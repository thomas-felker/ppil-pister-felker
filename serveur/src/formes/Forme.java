package formes;
import cadre.CadreDessin;

import exceptions.FormeManquanteException;

public abstract class Forme {
    private Forme suivant = null;
    public CadreDessin cadre;
    private Vecteur2D position;
    private Couleur color;

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

    public void traiter(String query) throws Exception {
        if (saitDessiner(query)){
            dessiner(query);
        } else if (aUnSuivant())  {
            getSuivant().traiter(query);
        } else {
            throw new FormeManquanteException();
        }
    }

    private Forme getSuivant() { return suivant; }

    private boolean aUnSuivant() { return suivant != null; }

    public abstract void dessiner(String query) throws Exception;

    public abstract boolean saitDessiner(String query);
}
