package formes;

import cadre.CadreDessin;

public class Segment extends Forme {
    private Vecteur2D arrivee;
    private Couleur color;
    private String args[];

    public Segment(Forme suivant, CadreDessin cadre) {
        super(suivant, cadre);
        arrivee = new Vecteur2D(0,0);
    }

    @Override
    public void dessiner(String query) throws Exception {
        args = query.split(",");
        cadre.graphics.setColor(this.getCouleur().getColor());
        cadre.graphics.drawLine(getPosition().getX(), getPosition().getY(), arrivee.getX(),arrivee.getY());

        cadre.getBufferStrategy().show();
    }

    @Override
    public boolean saitDessiner(String query) {
        args = query.split(",");
        System.out.println(args[0]);
        if (!args[0].equalsIgnoreCase("Segment")) {
            return false;
        } else {
            this.getCouleur().setName(args[1]);
            this.getPosition().setXY(Integer.parseInt(args[2].trim()), Integer.parseInt(args[3].trim()));
            arrivee.setXY(Integer.parseInt(args[4].trim()), Integer.parseInt(args[5].trim()));
            return true;
        }
    }
}
