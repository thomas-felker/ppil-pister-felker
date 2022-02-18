package formes;

import cadre.CadreDessin;

import java.awt.*;
import java.lang.reflect.Field;

public class Cercle extends Forme {
    private Vecteur2D rayon;
    private int x1, x2, y1, y2;
    private String name;
    private String color_;
    private String args[];


    public Cercle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
    }

    //-----------
    public static Color stringToColor(final String value) {
        if (value == null) {
            return Color.black;
        }
        try {
            // get color by hex or octal value
            return Color.decode(value);
        } catch (NumberFormatException nfe) {
            // if we can't decode lets try to get it by name
            try {
                // try to get a color by name using reflection
                final Field f = Color.class.getField(value);

                return (Color) f.get(null);
            } catch (Exception ce) {
                // if we can't get any color return black
                return Color.black;
            }
        }
    }

    // -------------
    @Override
    public void dessiner(String query) throws Exception {
        Color couleur = stringToColor(color_);
        System.out.println(color_);
        System.out.println(couleur.toString());
        args = query.split(",");
        cadre.graphics.setColor(couleur);
        cadre.graphics.fillOval(x1,y1,x2,y2);

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        if (!args[0].equalsIgnoreCase("Cercle")) {
            return false;
        } else {
            x1 = Integer.parseInt(args[1].trim());
            y1 = Integer.parseInt(args[2].trim());
            color_ = args[3];
            x2 = Integer.parseInt(args[4].trim());
            y2 = Integer.parseInt(args[5].trim());

            return true;
        }
    }
}
