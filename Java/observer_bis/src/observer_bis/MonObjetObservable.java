package observer_bis;

public class MonObjetObservable extends ObjetObservable{
	private int i;
	
	public int getI() {
		return i;
	}


	public void plus() { 
		this.i++; 
		this.etat = true;
		this.prevenirObservateur();
		this.etat = false;
	}

	public void moins() { 
		this.i--; 
		this.etat = true;
		this.prevenirObservateur();
		this.etat = false;
	}


}
