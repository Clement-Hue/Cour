package decorator;

public class Sucre extends Decorateur {
	
	public Sucre(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		System.out.println("verser une dose de sucre");
		this.boisson.verser();
	}
}
