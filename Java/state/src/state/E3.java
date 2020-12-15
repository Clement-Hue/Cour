package state;

public class E3 extends State {

	public E3(Machine machine) {
		super(machine);
	}

	@Override
	public void a() {
		this.machine.setState(new E3(machine));
	}

	@Override
	public void b() {
		this.machine.setState(new E4(machine));
	}

}
