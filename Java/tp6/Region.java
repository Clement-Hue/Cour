import java.util.Map;

class Region implements Cloneable{
    private String name;
    private Map<Region, Double> neighbors;

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
    public void setName(String name) {
        this.name = name;
    }

    public void setNeighbor(Map<Region, Double> neighbors) {
        this.neighbors = neighbors;
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
        if ( obj instanceof Region && ((Region) obj).getName() == name) return true;
        return false;
    }



}