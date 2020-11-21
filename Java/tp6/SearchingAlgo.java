import java.util.List;

public interface SearchingAlgo {

	List<Region> findAWay(String departName, String arriveName) throws UnknownVilleException;

	Carte getCarte();

	List<Region> getPath();

}