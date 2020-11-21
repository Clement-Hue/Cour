package decorator;

public class Eau extends Decorateur {

	public Eau(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		System.out.println("verser eau");
		this.boisson.verser();
	}

}
