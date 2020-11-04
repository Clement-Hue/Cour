import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Carte implements Cloneable{
    private List<Region> lRegions;
    

    public Carte(List<Region> lRegions) {
        this.lRegions = lRegions;
    }

    public List<Region> getlRegions() {
        return lRegions;
    }


    public Region findRegionByName(String name) {
        for ( Region region: lRegions) {
            if (region.getName().equals(name)) return region;
        }
        return null;
    }
    public void setlRegions(List<Region> lRegions) {
        this.lRegions = lRegions;
    }

    public void show() {
        for (Region region: lRegions){
            System.out.println(region + " voisin(s): " );
            for (Map.Entry<Region, Double> neighbor: region.getNeighbor().entrySet()) {
                System.out.println(neighbor);
            }
        System.out.print(System.lineSeparator());
      }
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        List<Region> copyRegions = new ArrayList<>();
        for (Region region: lRegions) {
            copyRegions.add((Region) region.clone());
        }
        Carte carte = new Carte(copyRegions);
        carte.linkedRegion();
        return carte;
    }

	private void linkedRegion() {
		for (Region region: getlRegions()) {
            Map<Region,Double> newNeighbors = new HashMap<>();
			for (Map.Entry<Region, Double> neighbor: region.getNeighbor().entrySet()) {
			    for (Region reg: getlRegions()) {
			        if (reg.equals(neighbor.getKey())) newNeighbors.put(reg, neighbor.getValue());
			    }
			}
			region.setNeighbor(newNeighbors);
        }
	}

	public void removeRegion(Region current) {
		lRegions.remove(current);
		for (Region region: lRegions) {
			region.getNeighbor().remove(current);
		}
	}

}
