public class MuseeRegional extends Musee {
    public String affiche() {
        return "je suis une musée régional";
    }

    public void accept(Visiteur visiteur) {
        visiteur.visit(this);
    }
}