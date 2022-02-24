package formes;

import cadre.CadreDessin;

import java.awt.*;

public class Triangle extends Forme {
    private Vecteur2D a,b,c;
    private String args[];
    private Polygon triangle;

    public Triangle(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        this.a = new Vecteur2D();
        this.b = new Vecteur2D();
        triangle = new Polygon();
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(Color.blue);
        System.out.println(getPosition());
        System.out.println(a);
        System.out.println(b);
        cadre.graphics.fillPolygon(new int[]{getPosition().getX(), a.getX(), b.getX()},
                new int[]{getPosition().getY(), a.getY(), b.getY()},
                3);

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        if (!args[0].equalsIgnoreCase("Triangle")) {
            return false;
        } else {
            this.getCouleur().setName(args[1]);
            this.getPosition().setXY(Integer.parseInt(args[2].trim()), Integer.parseInt(args[3].trim()));
            this.a.setXY(Integer.parseInt(args[4].trim()), Integer.parseInt(args[5].trim()));
            this.b.setXY(Integer.parseInt(args[6].trim()), Integer.parseInt(args[7].trim()));

            return true;
        }
    }
}
