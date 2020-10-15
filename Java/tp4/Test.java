class Test{
    public static void main(String[] args){
        Liste c1 = new Cellule(2,  new Cellule(4, new Vide()));
        ListIter liste = new ListIter(c1);
        // for (Integer val: liste) {
        //     System.out.println(val);
        // }
    }
}