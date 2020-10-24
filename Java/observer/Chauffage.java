public class Chauffage implements Observer{
    Temperature temperature;
    boolean active = false;
    public Chauffage (Temperature temperature) {
        this.temperature = temperature;
    }

    @Override
    public void update() {
        if ( temperature.getTemp() > 30 ) {
            this.turnOff();
        } else this.turnOn();
    }
    public void turnOff() {
        this.active = false;
        System.out.println("chauffage éteind");
    }
    public void turnOn() {
        this.active = true;
        System.out.println("chauffage allumé");
    }

}
