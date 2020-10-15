class Free extends User { 
    static final int MAX_SONG = 3;
    Free(String nom, String prenom, int id) {super(nom,prenom, id);}
    Free(){ super("nom","prénom",1); }

    public int getNbSongListened() { return nbSongListened; }

    @Override
    public boolean canListen() {
        if (this.nbSongListened > MAX_SONG) return false;
        return true;
    }
    public void subscribe(){ /*todo */ }
}