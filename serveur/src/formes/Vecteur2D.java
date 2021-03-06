package formes;

import cadre.CadreDessin;

import java.util.Objects;

public class Vecteur2D {
    private int x, y;
    /**
     @brief Constructeur par défaut  
     */
    public Vecteur2D() {}

     /**
     @brief Constructeur  avec des coordonées 
     */
    public Vecteur2D(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }
    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }
    public void setY(int y) {
        this.y = y;
    }

    public void setXY( int x, int y) {
        setX(x);
        setY(y);
    }

    public void WorldScreen(CadreDessin cadre) {

    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vecteur2D vecteur2D = (Vecteur2D) o;
        return x == vecteur2D.x && y == vecteur2D.y;
    }

    @Override
    public String toString() {
        return "Vecteur2D{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

}
