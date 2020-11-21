package decorator;

public class Moka extends Cafe {
	
	public Moka(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		super.verser();
		System.out.println("de Moka");
		this.boisson.verser();
	}
}
