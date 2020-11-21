package decorator;

public class Test {

	public static void main(String[] args) {
		BoissonFactory boissonFactory = new BoissonFactory();
		Boisson boisson = boissonFactory.createBoisson("dry cappuccino");
		boisson.verser();
	}

}
