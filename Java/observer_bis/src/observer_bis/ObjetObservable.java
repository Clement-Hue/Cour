package observer_bis;

import java.util.ArrayList;
import java.util.List;

public abstract class ObjetObservable {
	protected List<ObjetObservateur> listObs = new ArrayList<>();
	protected boolean etat = false;
	
	public final boolean getEtat() {
		return etat;
	}

	public boolean ajoutObservateur(ObjetObservateur o) {
		this.listObs.add(o);
		return true;
	}

	public void prevenirObservateur() {
		if (!etat) 
			return;
		for (ObjetObservateur observateur: this.listObs) {
			observateur.action(this);
		}
	}

}
