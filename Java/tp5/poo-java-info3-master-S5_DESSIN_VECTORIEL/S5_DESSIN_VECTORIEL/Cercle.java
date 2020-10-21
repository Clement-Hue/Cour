import java.awt.Graphics2D ;

public class Cercle implements Figure {
    
    int x  ;
    int y  ;

    int rayon;

    Cercle(int _x, int _y, int rayon) {
        x = _x ;
        y = _y ;
        this.rayon = rayon;
    }

    public void draw(Graphics2D g){
        g.drawOval(x, y, rayon, rayon);
    }
}