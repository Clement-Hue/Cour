package decorator;

public class Gobelet implements Boisson {

	@Override
	public void verser() {
		System.out.println("mise en place du gobelet");
	}

}
