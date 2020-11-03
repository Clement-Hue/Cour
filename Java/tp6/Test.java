import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;

class Test {
   public static void main(String[] args) {
      Carte carte = initCarte();
      carte.show();
      try {
         Way way = new Way((Carte) carte.clone());
         way.findAWay( args.length > 0 ? args[0] : "Rennes", args.length > 0 ? args[1] : "Angers");
         System.out.println(way);
      } catch(CloneNotSupportedException e) {
         System.out.println("erreur de clonage");
      }
   } 

   static public Carte initCarte() {
      Region brest = new Region("Brest"); Region rennes = new Region("Rennes"); Region rouen = new Region("Rouen" );
      Region nantes = new Region("Nantes"); Region paris = new Region("Paris") ; Region leMans = new Region("Le Mans");
      Region angers = new Region("Angers") ; Region tours = new Region("Tours"); Region poitiers = new Region("Poitiers");
      brest.setNeighbor(Map.of(rennes, 2.4));
      rennes.setNeighbor(Map.of(brest, 2.4, rouen, 2.8, nantes, 1.05, leMans, 0.9));
      rouen.setNeighbor(Map.of(rennes, 2.8, leMans, 1.9, paris, 1.2));
      paris.setNeighbor(Map.of(rouen, 1.2, leMans, 1.8));
      leMans.setNeighbor(Map.of(paris, 1.8, rouen, 1.9, rennes, 0.9, angers, 0.95, tours, 1.1));
      nantes.setNeighbor(Map.of(rennes, 1.05, angers, 0.95, poitiers, 2.1));
      angers.setNeighbor(Map.of(leMans, 0.95, nantes, 0.95, tours, 1.2));
      tours.setNeighbor(Map.of(leMans, 1.1, poitiers, 0.8, angers, 1.2));
      poitiers.setNeighbor(Map.of(nantes, 2.1, tours, 0.8));
      return new Carte(new ArrayList<>(Arrays.asList(
         brest, rennes, rouen, paris, leMans, nantes, angers, tours, poitiers
      )));
   }

}