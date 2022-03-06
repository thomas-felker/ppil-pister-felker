package formes;

import java.awt.*;

public class Couleur {
    private String name;

    public Couleur() {
    }

    public Couleur(String couleur) { name = couleur; }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    /**
     @brief Retourne la couleur demander par le client 
     */

    public Color getColor() {
        String tmp = getName().toLowerCase().replaceAll(" ", "");
        switch(tmp) {
            case "black" : return Color.black;
            case "blue" : return Color.blue;
            case "red" : return Color.red;
            case "green" : return Color.green;
            case "yellow" : return Color.yellow;
            case "cyan" : return Color.cyan;
            default : return Color.orange;
        }
    }

    public String toString() { return name; }
}
