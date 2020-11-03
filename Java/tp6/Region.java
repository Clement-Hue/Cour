import java.util.HashMap;
import java.util.Map;


class Region implements Cloneable{
    String name;
    Map<Region, Double> neighbors;

    public Region(String name, Map<Region, Double> neighbors){
        this.name = name;
        this.neighbors = neighbors;
    }

    public Region(String name){
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }

    public void setNeighbor(Map<Region, Double> neighbors) {
        this.neighbors = neighbors;
    }
    public void setNeighbor(Carte carte) {
        Map<Region,Double> newNeighbors = new HashMap<>();
        for (Map.Entry<Region, Double> neighbor: neighbors.entrySet()) {
            for (Region region: carte.getlRegions()) {
                if (region.equals(neighbor.getKey())) newNeighbors.put(region, neighbor.getValue());
            }
        }
        this.setNeighbor(newNeighbors);
    }
    public Map<Region, Double> getNeighbor() {
        return neighbors;
    }
    public String getName() {
        return name;
    }
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }

    @Override
    public boolean equals(Object obj) {
        if (((Region) obj).getName() == name) return true;
        return false;
    }

}