package decorator;

public abstract class Cafe extends Decorateur {

	public Cafe(Boisson boisson) {
		super(boisson);
	}
	
	@Override
	public void verser() {
		System.out.println("verser du café");
	}

}
