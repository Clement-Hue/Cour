import javax.swing.* ;
import java.awt.* ;


class MaFenetre extends JFrame {
    MaFenetre(){
	setSize(320,200+50);
	pan = new Paneau(new Palet()) ; 
/*	pan = new Paneau(new Pulsar()) ; */
	setContentPane(pan) ;
    }

     JPanel pan ;

}





class Paneau extends JPanel {

    Paneau(MovingObject p){
	super();
	this.p=p ;
    }
	
    MovingObject p ;

    @Override
    public void paintComponent (Graphics g){
	final Rectangle r = p.getRect() ;
	g.fillRect (r.x, r.y, r.width, r.height);
	p.deplace() ;
    }
    
}




public class Jeu {

    public static void main(String[] args){
	System.setProperty("sun.java2d.opengl", "true"); /* pour animation fluide */
	MaFenetre fen = new MaFenetre() ;
	fen.setVisible(true);
	fen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

	while (true){

	    fen.repaint() ; /* avec fen.repaint, la fenetre est effacee avant le paint,
				   avec pan.repaint, on garde la memoire de ce qui a été dessiné avant. */
	    
	    try {
		Thread.sleep(50);
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }	
	}
	
    }
}
