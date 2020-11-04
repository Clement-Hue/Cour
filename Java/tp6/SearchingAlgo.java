import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class SearchingAlgo {
	private static final double INFINI_VALUE = 999.0;
	private Carte carte;
	private List<Region> chemin = new ArrayList<>();
	private final Map<Region, Double> distance = new HashMap<>();
	private final Map<Region, Region> predecessor = new HashMap<>();


	public SearchingAlgo(Carte carte) {
		this.carte = carte;
	}

	private void dijkstra(final List<Region> sommet) {
		Region selected = getNextRegion(sommet);
		sommet.add(selected);
		for (Entry<Region, Double> neighbor : selected.getNeighbor().entrySet()) {
			double totalDistance = distance.get(selected) + neighbor.getValue();
			if (distance.get(neighbor.getKey()) > totalDistance) {
				distance.replace(neighbor.getKey(), totalDistance);
				predecessor.put(neighbor.getKey(), selected);
			}
		}
	}
	
	public List<Region> findAWay(String departName, String arriveName) throws UnknownVilleException {
		Region depart = carte.findRegionByName(departName);
		Region arrive = carte.findRegionByName(arriveName);
		if (depart == null || arrive == null) throw new UnknownVilleException();
		distance.put(depart, 0.0);
		final List<Region> sommet = new ArrayList<>();
		while (sommet.size() != carte.getlRegions().size()) {
			dijkstra(sommet); 
		}
		return chemin = retrieveChemin(depart, arrive);
	}

	public Carte getCarte() {
		return carte;
	}

	public List<Region> getChemin() {
		return chemin;
	}

	private Region getNextRegion(List<Region> sommet) {
		Region nextReg = null;
		for (Region reg: carte.getlRegions()) {
			if (sommet.contains(reg)) continue;
			if (!distance.containsKey(reg)) distance.put(reg, SearchingAlgo.INFINI_VALUE);
			if (nextReg == null || distance.get(reg) < distance.get(nextReg) ) {
				nextReg = reg;
			}
		}
		return nextReg;
	}

	private List<Region> retrieveChemin(Region depart, Region arrive) {
		List<Region> fastChemin = new ArrayList<>();
		Region current = arrive;
		while (!fastChemin.contains(depart)) {
			fastChemin.add(current);
			current = predecessor.get(current);
		}
		Collections.reverse(fastChemin);
		return fastChemin;
	}

	public void setCarte(Carte carte) {
		this.carte = carte;
	}

	public void setChemin(List<Region> chemin) {
		this.chemin = chemin;
	}

	@Override
	public String toString() {
		String text = "le chemin est";
		for (Region region : chemin) {
			text += System.lineSeparator() + region;
		}
		return text;
	}

}
