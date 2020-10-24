public class Rideau implements Observer {
    Temperature temperature;
    boolean open = false;
    public Rideau (Temperature temperature) {
        this.temperature = temperature;
    }

    @Override
    public void update() {
        if ( temperature.getTemp() > 30 ) {
            this.close();
        } else this.open();
    }
    public void open() {
        this.open = true;
        System.out.println("rideau ouvert");
    }
    public void close() {
        this.open = false;
        System.out.println("rideau fermé");
    }
 
}
