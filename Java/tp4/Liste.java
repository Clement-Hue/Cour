abstract class Liste{

    abstract int longueur();
    abstract boolean find(int n);
    abstract int max ();
    abstract Liste getNext();
    public String toString() {
        return "cette liste a pour longeueur " + this.longueur() + " le max est " + this.max();
    }
    abstract public boolean isEmpty();
}