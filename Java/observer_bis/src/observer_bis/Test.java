package observer_bis;

public class Test {

	public static void main(String[] args) {
		ObjetObservable obj = new MonObjetObservable();
		new MonObjetObservateur(obj);
		((MonObjetObservable)obj).plus();
		((MonObjetObservable)obj).moins();
		((MonObjetObservable)obj).moins();
	}

}
