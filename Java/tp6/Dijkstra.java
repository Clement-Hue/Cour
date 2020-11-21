import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Dijkstra implements SearchingAlgo {
	private Carte carte;
	private List<Region> path = new ArrayList<>();

	public Dijkstra(final Carte carte) {
		this.carte = carte;
	}

	private void dijkstra( final List<Region> sommet) {
		final Region selected = getNextRegion(sommet);
		sommet.add(selected);
		selected.getNeighbor().forEach((neighbor, value) -> {
			final double totalDistance = selected.getDistance() + value;
			if (neighbor.getDistance() > totalDistance) {
				neighbor.setDistance(totalDistance);
				neighbor.setPredecessor(selected);
			}
		});
	}

	@Override
	public final List<Region> findAWay(final String departName, final String arriveName) throws UnknownVilleException {
		final Region depart = carte.findRegionByName(departName);
		final Region arrive = carte.findRegionByName(arriveName);
		if (depart == null || arrive == null) {
			throw new UnknownVilleException();
		}
		final List<Region> sommet = new ArrayList<>();
		depart.setDistance(0.0);
		while (sommet.size() != carte.getlRegions().size()) {
			dijkstra(sommet);
		}
		return path = retrievePathFromPredecessor(depart, arrive);
	}

	@Override
	public Carte getCarte() {
		return carte;
	}

	private Region getNextRegion(final List<Region> sommet) {
		Region nextReg = null;
		for (final Region reg : carte.getlRegions()) {
			if (sommet.contains(reg))
				continue;
			if (nextReg == null || reg.getDistance() < nextReg.getDistance()) {
				nextReg = reg;
			}
		}
		return nextReg;
	}

	@Override
	public List<Region> getPath() {
		return path;
	}

	private List<Region> retrievePathFromPredecessor(final Region depart, final Region arrive) {
		final List<Region> newPath = new ArrayList<>();
		for (Region current = arrive; !newPath.contains(depart); current = current.getPredecessor()) {
			newPath.add(current);
		}
		Collections.reverse(newPath);
		return newPath;
	}

	public void setCarte(final Carte carte) {
		this.carte = carte;
	}

	public void setPath(final List<Region> path) {
		this.path = path;
	}

	@Override
	public final String toString() {
		String text = "le chemin est";
		for (final Region region : path) {
			text += System.lineSeparator() + region;
		}
		return text;
	}

}
