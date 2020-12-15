package state;

public class E2 extends State {

	public E2(Machine machine) {
		super(machine);
	}

	@Override
	public void a() {
		this.machine.setState(new E4(machine));
	}

	@Override
	public void b() {
		this.machine.setState(new E2(machine));
	}

}
