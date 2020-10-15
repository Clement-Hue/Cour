import javax.swing.* ;
import java.awt.* ;


class MaFenetre extends JFrame {
    JPanel pan ;
	MovingObject list_pal[]; 

	public int getNbPalet() {
		int nbPalet = 0;
		for (MovingObject pal : this.list_pal) {
			if (pal instanceof Palet) nbPalet++;
		}
		return nbPalet;
	}

	public int getNbPulsar() {
		int nbPulsar = 0;
		for (MovingObject pal : this.list_pal) {
			if (pal instanceof Pulsar) nbPulsar++;
		}
		return nbPulsar;
	}

    MaFenetre(int nb_pal){
		this.list_pal = new MovingObject[nb_pal];
		for (int i = 0; i< nb_pal; i++) {
			list_pal[i] = new Pulsar(15*(i+1), 15*(i+1));
		}
		setSize(320,200+50);
		pan = new Paneau(list_pal) ;
		setContentPane(pan) ;
    }
}



class Paneau extends JPanel {
    MovingObject[] listPan ;
    Paneau(MovingObject [] listPan){
		super();
		this.listPan=listPan;
    }

    @Override
    public void paintComponent (Graphics g){
		Rectangle [] rectList = new Rectangle[listPan.length];
		for (int i = 0; i< listPan.length; i++) {
			rectList[i] = listPan[i].getRect();
			g.fillRect (rectList[i].x,rectList[i].y,rectList[i].width,rectList[i].height);
			listPan[i].deplace();
		}
    }
}



public class Jeu {

    public static void main(String[] args) throws InterruptedException {
		System.setProperty("sun.java2d.opengl", "true");
		MaFenetre fen = new MaFenetre(3) ;
		fen.setVisible(true);
		fen.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		while (true){
			fen.repaint() ; 
			Thread.sleep(50);
		}
		
    }
}
