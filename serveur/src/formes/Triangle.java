package formes;

import cadre.CadreDessin;

public class Triangle extends Forme {
    private Vecteur2D a;
    private Vecteur2D b;
    private Vecteur2D c;

    public Triangle(Forme suivant, CadreDessin cadre) {
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
