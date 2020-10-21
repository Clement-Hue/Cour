import javax.swing.* ;
import java.awt.* ;
import java.util.ArrayList;
import java.util.List;


class MaFenetre extends JFrame {
    MaFenetre(Figure r){
        setSize(320,200+50);
        setContentPane(new Paneau(r)) ;
    }
}





class Paneau extends JPanel {

    Figure p ;

    Paneau(Figure p){
        this.p=p ;
    }

    @Override
    public void paintComponent (Graphics g){
        if (g instanceof Graphics2D)
            p.draw((Graphics2D) g) ;
        else throw new RuntimeException();
    }
    
}




public class Test {

    public static void main(String[] args){
        List<Figure> listFigure = new ArrayList<>();
        listFigure.add( new Rectangle(10, 10, 100 , 50));
        listFigure.add(new Cercle(30,30,50));
        listFigure.add(new ColoredFigure(new Cercle(60,60,100)));
        MaFenetre fen = new MaFenetre(new Groupe(listFigure));
        fen.setVisible(true);
        fen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
}
