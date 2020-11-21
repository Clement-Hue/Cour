class Test {

    public static void main(String[] args) {
        Visiteur visiteurFr = new VisiteurFR();
        Musee musee = new Musee();
        Musee museeRegional = new MuseeRegional();
        musee.accept(visiteurFr);
        museeRegional.accept(visiteurFr);
    }

}