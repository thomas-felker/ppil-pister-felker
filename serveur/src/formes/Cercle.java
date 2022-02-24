package formes;

import cadre.CadreDessin;

import java.awt.*;
import java.lang.reflect.Field;

public class Cercle extends Forme {
    private Vecteur2D rayon;
    private Couleur color;
    private String args[];


    public Cercle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        rayon = new Vecteur2D(0,0);
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(this.getCouleur().getColor());
        cadre.graphics.fillOval(getPosition().getX(), getPosition().getY(), rayon.getX(), rayon.getY());

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        if (!args[0].equalsIgnoreCase("Cercle")) {
            return false;
        } else {
            this.getCouleur().setName(args[1]);
            this.getPosition().setXY(Integer.parseInt(args[2].trim()), Integer.parseInt(args[3].trim()));
            rayon.setXY(Integer.parseInt(args[4].trim()), Integer.parseInt(args[5].trim()));

            return true;
        }
    }
}
