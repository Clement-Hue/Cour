package decorator;

public class Chocolat extends Decorateur {
	

	public Chocolat(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		System.out.println("verser une dose de chocolat");
		this.boisson.verser();
	}

}
