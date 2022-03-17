package cadre;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.Dimension;
 /**
     @brief Class utilisé pour recevoir les dessins réalisé dans le cadre  
*/
public class CadreDessin extends Frame
{
    public Graphics graphics;
    public double wratio, hratio;
    
    /**
     @brief Constructeur 
     */
    public CadreDessin(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
    {
        super(titre);

        Toolkit tk = Toolkit.getDefaultToolkit();

        int le, he; 

        Dimension dim = tk.getScreenSize(); 

        le = (int) dim.getWidth();
        he = (int) dim.getHeight();

        int bordGauche, bordSupérieur, l, h ;

        bordGauche = Math.max(0, ox);
        bordSupérieur = Math.max(0, oy);
        l = Math.min(largeur, le - bordGauche);
        h = Math.min(hauteur, he - bordSupérieur);
        this.setBounds(bordGauche, bordSupérieur, l, h);


        this.setVisible(true);


        this.setIgnoreRepaint(true);

        int numBuffers = 2;
        this.createBufferStrategy(numBuffers);
        Thread.sleep(150);  
        graphics = this.getBufferStrategy().getDrawGraphics();

        System.out.println("Largeur = " + largeur + ", hauteur = " + hauteur);
        int height = Toolkit.getDefaultToolkit().getScreenSize().height;
        int width = Toolkit.getDefaultToolkit().getScreenSize().width;
        System.out.println("Largeur = " + width + ", hauteur = " +height);

        wratio = width / largeur;
        hratio = height / hauteur;
        System.out.println("Largeur ratio = " + wratio + ", hauteur = " +hratio);
    }

}
