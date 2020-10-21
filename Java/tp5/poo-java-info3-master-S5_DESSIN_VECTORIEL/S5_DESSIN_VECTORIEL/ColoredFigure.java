import java.awt.Graphics2D;
import java.awt.Color;

public class ColoredFigure implements Figure{
    Figure figure;

    public ColoredFigure(Figure figure) {
        this.figure = figure;
    }
    
    @Override
    public void draw(Graphics2D graph) {
        graph.setColor(Color.BLUE);
        figure.draw(graph);
    }
}