package decorator;

public class BourbonSantos extends Cafe {
	
	public BourbonSantos(Boisson boisson) {
		super(boisson);
	}

	@Override
	public void verser() {
		super.verser();
		System.out.println("de Bourbon santos");
		this.boisson.verser();
	}

}
