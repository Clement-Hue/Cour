public class Musee {
    public String affiche() {
        return "je suis un musée";
    }

    public void accept(Visiteur visiteur) {
        visiteur.visit(this);
    }
}
