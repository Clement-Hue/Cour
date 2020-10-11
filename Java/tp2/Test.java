class Test{
    public static void main(String[] args){
        Liste c1 = new Cellule(2, (Liste) new Cellule(4, null));
        Liste c2 = new Vide();
        System.out.println(c1.toString());
    }
}