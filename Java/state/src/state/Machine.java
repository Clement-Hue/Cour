package state;

public class Machine {
	private State currentState = new E1(this);
	public void setState(State state) {
		currentState = state;
	}
	public void a() {
		this.currentState.a();
	}
	public void b() {
		this.currentState.b();
	}
	
	public State getCurrentState() {
		return currentState;
	}
}
