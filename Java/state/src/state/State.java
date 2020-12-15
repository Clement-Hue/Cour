package state;

public abstract class State {
	Machine machine;
	public State(Machine machine) {
		this.machine = machine;
	}
	public abstract void a();
	public abstract void b();
}
