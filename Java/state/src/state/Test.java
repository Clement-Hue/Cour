package state;

public class Test {

	public static void main(String[] args) {
		Machine m1 = new Machine();
		Machine m2 = new Machine();
		m1.a();
		m1.b();
		m1.b();
		m1.b();
		m1.a();
		System.out.println(m1.getCurrentState());
		m2.b();
		m2.b();
		m2.a();
		m2.a();
		m2.b();
		System.out.println(m2.getCurrentState());
	}

}
