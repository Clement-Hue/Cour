class Vide extends Liste {
    public int longueur() { return 0;}
    public boolean find(int n) { return false;}
    public int max() { return 0;}
    @Override
    Liste getNext() {
        return null;
    }
    @Override
    public boolean isEmpty() {
        return true;
    }
}