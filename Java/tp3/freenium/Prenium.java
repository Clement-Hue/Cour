class Prenium extends User {
    String creditCard;
    static final int COST = 10;

    Prenium(String nom, String prenom, int id) {super(nom,prenom, id);}

    public void setCreditCard(String creditCard) { this.creditCard = creditCard; }

    @Override
    public boolean canListen() { return true;}
    public void stopSub() {/*todo*/}
}