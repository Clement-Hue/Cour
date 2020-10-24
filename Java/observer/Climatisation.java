public class Climatisation implements Observer{
    Temperature temperature;
    boolean active = false;
    public Climatisation (Temperature temperature) {
        this.temperature = temperature;
    }

    @Override
    public void update() {
        if ( temperature.getTemp() > 30 ) {
            this.turnOn();
        } else this.turnOff();
    } 

    public void turnOff() {
        this.active = false;
        System.out.println("climatisation éteinte");
    }
    public void turnOn() {
        this.active = true;
        System.out.println("climatisation allumé");
    }
    
}
