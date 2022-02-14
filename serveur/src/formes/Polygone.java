package formes;

import cadre.CadreDessin;

public class Polygone extends Forme {
    public Polygone(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
    }

    @Override
    public void dessiner(String query) throws Exception {

    }

    @Override
    public boolean saitDessiner(String query) {
        return false;
    }
}
