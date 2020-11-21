import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class Carte implements Cloneable, Serializable {

	private static final long serialVersionUID = -5494713157942850234L;


	private List<Region> lRegions;
	
	public Carte(final File file) {
		this.lRegions = null;
		try {
			final ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file));
			final Carte carte = (Carte) ois.readObject();
			this.lRegions = carte.lRegions;
			ois.close();
		} catch (IOException | ClassNotFoundException e) {
			e.printStackTrace();
		}
	}

	public Carte(final List<Region> lRegions) {
		this.lRegions = lRegions;
	}

	@Override
	public Object clone() throws CloneNotSupportedException {
		final List<Region> copyRegions = new ArrayList<>();
		for (final Region region : lRegions) {
			copyRegions.add((Region) region.clone());
		}
		final Carte carte = new Carte(copyRegions);
		carte.linkedRegion();
		return carte;
	}

	public Region findRegionByName(final String name) {
		for (final Region region : lRegions) {
			if (region.getName().equals(name))
				return region;
		}
		return null;
	}

	public List<Region> getlRegions() {
		return lRegions;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj instanceof Carte && equalsCarte((Carte) obj)) 
			return true;
		return false;
	}

	private boolean equalsCarte(Carte carte) {
		if (carte.getlRegions().size() != this.lRegions.size()) 
			return false;
		for (Region region: carte.getlRegions()) {
			if (!this.lRegions.contains(region))
				return false;
		}
		return true;
	}

	private void linkedRegion() {
		for (final Region region : getlRegions()) {
			final Map<Region, Double> newNeighbors = new HashMap<>();
			region.getNeighbor().forEach((neighbor, value) -> {
				for (final Region reg : getlRegions()) {
					if (reg.equals(neighbor))
						newNeighbors.put(reg, value);
				}
			});
			region.setNeighbor(newNeighbors);
		}
	}

	public void removeRegion(final Region current) {
		lRegions.remove(current);
		lRegions.forEach(reg -> reg.getNeighbor().remove(current));
	}

	public void serialization(final File file) {
		try {
			final ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file));
			oos.writeObject(this);
			oos.close();
		} catch (final IOException e1) {
			e1.printStackTrace();
		}
	}


	@Override
	public String toString() {
		String str = new String();
		for (final Region region : lRegions) {
			str += region + " voisin(s): ";
			for (final Entry<Region, Double> neighbor : region.getNeighbor().entrySet()) {
				str += neighbor.getKey() + " " + neighbor.getValue();
			}
			str += System.lineSeparator();
		}
		return str;
	}

}
