
public enum Ville {
	RENNES("Rennes"), BREST("Brest"), NANTES("Nantes"), ANGERS("Angers"), PARIS("Paris"), TOUR("Tour"), ROUEN("Rouen"),
	LE_MANS("Le Mans"), POITIERS("Poitiers");

	private String villeName;

	Ville(final String villeName) {
		this.villeName = villeName;
	}

	@Override
	public String toString() {
		return villeName;
	}

}
