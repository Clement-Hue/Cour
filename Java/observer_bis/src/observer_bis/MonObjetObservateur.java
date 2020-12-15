package observer_bis;

public class MonObjetObservateur implements ObjetObservateur{
	private ObjetObservable observable;

	public MonObjetObservateur(ObjetObservable observable) {
		this.observable = observable;
		observable.ajoutObservateur(this);
	}

	@Override
	public void action(ObjetObservable o) {
		if (o instanceof MonObjetObservable) {
			System.out.println(((MonObjetObservable) o).getI());
		
		}
	}
	

}
