import java.awt.Graphics2D;
import java.util.List;

public class Groupe implements Figure {
    List<Figure> listFigure;

    public Groupe(List<Figure> listFigure) {
        this.listFigure = listFigure;
    }

   @Override
   public void draw(Graphics2D graph) {
       for (Figure figure : listFigure) {
           figure.draw(graph);
       }
   } 
}