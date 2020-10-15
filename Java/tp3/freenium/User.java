abstract class User { 
    private String nom;
    private String prenom;
    private int [] favoriteList;
    private int id;
    protected int nbSongListened = 0;

    public int getId() { return id; }
    public String getNom() { return nom; }
    public String getPrenom() { return prenom; }
    public int getNbSongListened() { return nbSongListened; }

    User(String nom, String prenom, int id) {
        this.nom = nom; this.prenom = prenom; this.id = id;
    }
    User() {
        nom= "nom"; prenom = "prénom"; id = 1;
    }

    public void reset() {
        this.nbSongListened = 0;
    }

    public String getSong(int song) {
        return "morceau";
    }

    public int [] getFavoriteList() {
        return this.favoriteList;
    }

    abstract public boolean canListen();
}