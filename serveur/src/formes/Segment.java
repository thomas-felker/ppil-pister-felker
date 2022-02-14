package formes;

import cadre.CadreDessin;

public class Segment extends Forme {
    private Vecteur2D vecteur;
    private int x1, x2, y1, y2;
    private String name;
    private String args[];

    public Segment(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
    }

    @Override
    public void dessiner(String query) throws Exception {
        args = query.split(",");
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
            x1 = Integer.parseInt(args[1].trim());
            y1 = Integer.parseInt(args[2].trim());
            x2 = Integer.parseInt(args[3].trim());
            y2 = Integer.parseInt(args[4].trim());

            return true;
        }
    }
}
