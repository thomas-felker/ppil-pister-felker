package formes;

import cadre.CadreDessin;

public class Segment extends Forme {
    private Vecteur2D vecteur;
    private int x1, x2, y1, y2;
    private String name;
    private Couleur color;
    private String args[];

    public Segment(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
    }

    @Override
    public void dessiner(String query) throws Exception {
        args = query.split(",");
        cadre.graphics.setColor(color.getColor());
        cadre.graphics.drawLine(x1,y1,x2,y2);

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        System.out.println(args[0]);
        if (!args[0].equalsIgnoreCase("Segment")) {
            return false;
        } else {
            color = new Couleur(args[1]);
            x1 = Integer.parseInt(args[2].trim());
            y1 = Integer.parseInt(args[3].trim());
            x2 = Integer.parseInt(args[4].trim());
            y2 = Integer.parseInt(args[5].trim());

            return true;
        }
    }
}
