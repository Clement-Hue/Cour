import java.util.Iterator;

class ListIter implements Iterable<Integer> {
    Integer[] values;

    public ListIter(Liste s) {
        this.values = new Integer[s.longueur()];
        Liste current = s;
        for (int i = 0; !(current.isEmpty()); i++) {
            values[i] = new Integer( ((Cellule) current).getVal());
            current = ((Cellule) current).getNext();
        }
    }

    public Iterator<Integer> iterator() {
        return new ListIterator();
    }

}