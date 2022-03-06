package formes;

import cadre.CadreDessin;

import java.util.ArrayList;

public class Polygone extends Forme {
    private ArrayList<Vecteur2D> points;
    private int nbPoints;
    private int [] x,y;

    /**
     @brief Constructeur 
     */
    public Polygone(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        points = new ArrayList<Vecteur2D>();
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(this.getCouleur().getColor());

        x = new int[points.size()];
        y = new int[points.size()];

        for (int i=0; i<points.size(); i++) {
            x[i] = points.get(i).getX();
            y[i] = points.get(i).getY();
        }

        cadre.graphics.fillPolygon(x, y, points.size());
        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        test = query.split(":");
        if (!test[0].equalsIgnoreCase("Polygone") && !test[0].equalsIgnoreCase("Triangle")) {
            return false;
        } else {
            args = test[1].split(",");
            this.getCouleur().setName(args[0]);
            int cmp = args.length;
            for (int i=2; i<cmp; i=i+2) {
                points.add(new Vecteur2D(Integer.parseInt(args[i-1].trim()), Integer.parseInt(args[i].trim())));
            }
            return true;
        }
    }
}
