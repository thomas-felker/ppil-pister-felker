package formes;
import cadre.CadreDessin;

import exceptions.FormeManquanteException;

public abstract class Forme {
    private Forme suivant = null;
    public CadreDessin cadre;

    public Forme(Forme suivant, CadreDessin cadre) {
        this.suivant = suivant;
        this.cadre = cadre;
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
