package decorator;

public class Lait extends Decorateur {


	public Lait(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		System.out.println("verser une dose de lait");
		this.boisson.verser();
	}

}
