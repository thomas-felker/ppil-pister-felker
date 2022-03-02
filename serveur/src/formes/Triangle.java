package formes;

import cadre.CadreDessin;

import java.awt.*;

public class Triangle extends Forme {
    private Vecteur2D a,b,c;
    private String args[];
    private Polygon triangle;
    private double ax, ay, bx, by, cx, cy;

    public Triangle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        this.a = new Vecteur2D();
        this.b = new Vecteur2D();
        triangle = new Polygon();
    }

    @Override
    public void dessiner(String query) throws Exception {
        Insets insets = cadre.getInsets();
        int top = insets.top;
        int left = insets.left;
        int right = insets.right;
        int bottom = insets.bottom;

        System.out.println("Alignement X et Y : " + cadre.getAlignmentX() + ", " + cadre.getAlignmentY());
        System.out.println("X et Y : " +cadre.getX() + ", " + cadre.getX());
        System.out.println("Insets : " + insets.toString());

        int getx = 1;
        int gety = 1;

        cadre.graphics.setColor(this.getCouleur().getColor());

        int[] x = new int []{(int) ax * getx, (int) bx * getx, (int) cx * getx};
        int[] y = new int []{(int) ay * gety, (int) by * gety, (int) cy * gety};

        cadre.graphics.fillPolygon(x, y, 3);

        /* cadre.graphics.fillPolygon(new int[]{getPosition().getX(), a.getX(), b.getX()},
                new int[]{getPosition().getY(), a.getY(), b.getY()},
                3);
        */

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        if (!args[0].equalsIgnoreCase("Triangle")) {
            return false;
        } else {
                        this.getCouleur().setName(args[1]);
            ax = Double.parseDouble(args[2]);
            ay = Double.parseDouble(args[3]);
            bx = Double.parseDouble(args[4]);
            by = Double.parseDouble(args[5]);
            cx = Double.parseDouble(args[6]);
            cy = Double.parseDouble(args[7]);
            /*
            this.getPosition().setXY(Integer.parseInt(args[2].trim()) + left, Integer.parseInt(args[3].trim()) + top);
            this.a.setXY(Integer.parseInt(args[4].trim()) + left, Integer.parseInt(args[5].trim()) + top);
            System.out.println(Integer.parseInt(args[6].trim()));
            this.b.setXY(Integer.parseInt(args[6].trim()) + left, Integer.parseInt(args[7].trim()) + top);
            */
            return true;
        }
    }
}
