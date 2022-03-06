package formes;

import cadre.CadreDessin;

import java.awt.*;
import java.lang.reflect.Field;

public class Cercle extends Forme {
    private int rayon;

    /**
     @brief Constructeur 
     */
    public Cercle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(this.getCouleur().getColor());
        cadre.graphics.fillOval(getPosition().getX(), getPosition().getY(), rayon, rayon);

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        test = query.split(":");
        if (!test[0].equalsIgnoreCase("Cercle")) {
            return false;
        } else {
            args = test[1].split(",");
            this.getCouleur().setName(args[0]);
            this.getPosition().setXY(Integer.parseInt(args[1].trim()), Integer.parseInt(args[2].trim()));
            rayon = Integer.parseInt(args[3].trim());

            return true;
        }
    }
}
