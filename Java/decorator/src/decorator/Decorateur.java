package decorator;

public abstract class Decorateur implements Boisson {
	Boisson boisson;
	
	public Decorateur(Boisson boisson) {
		this.boisson = boisson;
	}

}
