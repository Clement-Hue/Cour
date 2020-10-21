import java.util.Iterator;

class Test{
    public static void main(String[] args){
        Liste c1 = new Cellule(2,  new Cellule(4, new Cellule(10, new Vide())));
        ListIter liste = new ListIter(c1);
        // Iterator it = liste.iterator();
        for (Integer val : liste)
            System.out.println(val);
    }
}