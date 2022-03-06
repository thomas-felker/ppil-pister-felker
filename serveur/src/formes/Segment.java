package formes;

import cadre.CadreDessin;

public class Segment extends Forme {
    private Vecteur2D arrivee;

     /**
     @brief Constructeur 
     */
    public Segment(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        arrivee = new Vecteur2D(0,0);
    }

    @Override
    public void dessiner(String query) throws Exception {
        cadre.graphics.setColor(this.getCouleur().getColor());
        cadre.graphics.drawLine(getPosition().getX(), getPosition().getY(), arrivee.getX(),arrivee.getY());

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        test = query.split(":");
        if (!test[0].equalsIgnoreCase("Segment")) {
            return false;
        } else {
            args = test[1].split(",");
            this.getCouleur().setName(args[0]);
            this.getPosition().setXY(Integer.parseInt(args[1].trim()), Integer.parseInt(args[2].trim()));
            arrivee.setXY(Integer.parseInt(args[3].trim()), Integer.parseInt(args[4].trim()));
            return true;
        }
    }
}
