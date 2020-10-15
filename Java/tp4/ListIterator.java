import java.util.Iterator;
import java.util.NoSuchElementException;

public class ListIterator implements Iterator<Integer> {
    ListIter list;
    int current = 0;

    public boolean hasNext() {
        if (current < list.values.length) return true;
        return false;
    }

    public Integer next() throws NoSuchElementException{
        if (!hasNext()) { 
            throw new NoSuchElementException();
        } 
        return list.values[current++];
    }
}