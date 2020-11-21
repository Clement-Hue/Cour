import java.io.Serializable;
import java.util.Map;

class Region implements Cloneable, Serializable {
	private static final long serialVersionUID = 6961215819674375193L;
	private final String name;
	private Map<Region, Double> neighbors;
	private Double distance = 999.0;
	private Region predecessor = null;

	public Region(final String name) {
		this.name = name;
	}

	public Region(final String name, final Map<Region, Double> neighbors) {
		this.name = name;
		this.neighbors = neighbors;
	}

	public Region(final Ville ville) {
		this.name = ville.toString();
	}

	@Override
	public Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

	@Override
	public boolean equals(final Object obj) {
		if (this == obj)
			return true;
		if (obj instanceof Region && ((Region) obj).getName() == name)
			return true;
		return false;
	}

	public Double getDistance() {
		return distance;
	}

	public String getName() {
		return name;
	}

	public Map<Region, Double> getNeighbor() {
		return neighbors;
	}

	public Region getPredecessor() {
		return predecessor;
	}

	public void setDistance(final Double distance) {
		this.distance = distance;
	}

	public void setNeighbor(final Map<Region, Double> neighbors) {
		this.neighbors = neighbors;
	}

	public void setPredecessor(final Region predecessor) {
		this.predecessor = predecessor;
	}

	@Override
	public String toString() {
		return name;
	}

}