package formes;

import cadre.CadreDessin;

import java.awt.*;

public class Triangle extends Forme {
    private double ax, ay, bx, by, cx, cy;
    private Vecteur2D A, B, C;

    /**
     @brief Constructeur 
     */
    public Triangle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        A = new Vecteur2D(0,0);
        B = new Vecteur2D(0,0);
        C = new Vecteur2D(0,0);
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(this.getCouleur().getColor());

        int[] x = new int []{A.getX(), B.getX(), C.getX()};
        int[] y = new int []{A.getY(), B.getY(), C.getY()};

        cadre.graphics.fillPolygon(x, y, 3);
        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        test = query.split(":");
        if (!test[0].equalsIgnoreCase("oldTriangle")) {
            return false;
        } else {
            args = test[1].split(",");
            this.getCouleur().setName(args[0]);
            A.setXY(Integer.parseInt(args[1].trim()), Integer.parseInt(args[2].trim()));
            B.setXY(Integer.parseInt(args[3].trim()), Integer.parseInt(args[4].trim()));
            C.setXY(Integer.parseInt(args[5].trim()), Integer.parseInt(args[6].trim()));
            return true;
        }
    }
}
