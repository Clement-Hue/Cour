package state;

public class E1 extends State{

	public E1(Machine machine) {
		super(machine);
	}

	@Override
	public void a() {
		this.machine.setState(new E2(machine));
	}

	@Override
	public void b() {
		this.machine.setState(new E3(machine));
	}

}
