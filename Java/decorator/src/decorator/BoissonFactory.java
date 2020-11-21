package decorator;

public class BoissonFactory {
	
	public Boisson createBoisson(String boissonName) {
		if (boissonName.equals("cappuccino")) {
			return createCappuccino();
		}
		if (boissonName.equals("café")) {
			return new BourbonSantos(new Gobelet());
		}
		if (boissonName.equals("café allongé")) {
			return new BourbonSantos(new Eau(new Gobelet()));
		}
		if (boissonName.equals("café au lait")) {
			return new BourbonSantos(new Lait(new Gobelet()));
		}
		if (boissonName.equals("chocolat chaud")) {
			return new Chocolat(new Lait(new Gobelet()));
		}
		if (boissonName.equals("dry cappuccino")) {
			return new Lait(new Lait(createCappuccino()));
		}
		return null;
	}
	
	private Boisson createCappuccino() {
		return new BourbonSantos(new Lait(new Lait(new Chocolat(new Gobelet()))));
	}
	
}
