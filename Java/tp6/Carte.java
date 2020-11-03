import java.util.ArrayList;
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
        for (Region region: carte.getlRegions()) {
            region.setNeighbor(carte);
        }
        return carte;
    }

}
