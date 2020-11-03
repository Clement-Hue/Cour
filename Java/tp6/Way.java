import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Way {
   Carte carte ;
   List<Region> chemin;
   public Way(Carte carte) {
       this.carte = carte;
   }

   public List<Region> findAWay (String departName, String arriveName) {
        chemin = new ArrayList<>();
        Region depart = carte.findRegionByName(departName);
        Region arrive = carte.findRegionByName(arriveName);
        Region next = depart;
        while (next != null && !next.equals(arrive)) {
            chemin.add(next);
            next = nextRegion(next);
        }
        chemin.add(next);
        return chemin;
   }

   private Region nextRegion(Region region) {
        region.setPassed(true);
        for (Map.Entry<Region,Double> neighbor : region.getNeighbor().entrySet()) {
            if (!neighbor.getKey().getPassed()) return neighbor.getKey();
        }
        return null;
   }

   @Override
   public String toString() {
       String text = "le chemin est";
       for (Region region: chemin) {
            text += System.lineSeparator();
            text += region;
       }
       return text;
   }


}
