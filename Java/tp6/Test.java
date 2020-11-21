import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;

class Test {

	private static final String FILENAME = "./carte.ser";

	private static void deserialization(final String[] args, final File file) {
		final Carte carteFromFile = new Carte(file);
		System.out.println("Lecture de " + FILENAME);
		System.out.println(carteFromFile);
		try {
			final SearchingAlgo dijkstra = new Dijkstra((Carte) carteFromFile.clone());
			dijkstra.findAWay(args.length > 0 ? args[0] : Ville.RENNES.toString(),
					args.length > 0 ? args[1] : Ville.ANGERS.toString());
			System.out.println(dijkstra);
		} catch (CloneNotSupportedException | UnknownVilleException e) {
			System.out.println(e.getMessage());
		}
	}

	static public Carte initCarte() {
		final Region brest = new Region(Ville.BREST);
		final Region rennes = new Region(Ville.RENNES);
		final Region rouen = new Region(Ville.ROUEN);
		final Region nantes = new Region(Ville.NANTES);
		final Region paris = new Region(Ville.PARIS);
		final Region leMans = new Region(Ville.LE_MANS);
		final Region angers = new Region(Ville.ANGERS);
		final Region tours = new Region(Ville.TOUR);
		final Region poitiers = new Region(Ville.POITIERS);
		brest.setNeighbor(Map.of(rennes, 2.4));
		rennes.setNeighbor(Map.of(brest, 2.4, rouen, 2.8, nantes, 1.05, leMans, 0.9));
		rouen.setNeighbor(Map.of(rennes, 2.8, leMans, 1.9, paris, 1.2));
		paris.setNeighbor(Map.of(rouen, 1.2, leMans, 1.8));
		leMans.setNeighbor(Map.of(paris, 1.8, rouen, 1.9, rennes, 0.9, angers, 0.95, tours, 1.1));
		nantes.setNeighbor(Map.of(rennes, 1.05, angers, 0.95, poitiers, 2.1));
		angers.setNeighbor(Map.of(leMans, 0.95, nantes, 0.95, tours, 1.2));
		tours.setNeighbor(Map.of(leMans, 1.1, poitiers, 0.8, angers, 1.2));
		poitiers.setNeighbor(Map.of(nantes, 2.1, tours, 0.8));
		return new Carte(
				new ArrayList<>(Arrays.asList(brest, rennes, rouen, paris, leMans, nantes, angers, tours, poitiers)));
	}

	public static void main(final String[] args) {
		final File file = new File(Test.FILENAME);
		if (file.exists())
			deserialization(args, file);
		else
			serialization(file);
	}

	private static void serialization(final File file) {
		System.out.println("Création de " + FILENAME);
		final Carte carte = initCarte();
		carte.serialization(file);
	}

}