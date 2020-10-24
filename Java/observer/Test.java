public class Test {
    public static void main(String[] args) {
        Temperature temperature = new Temperature();
        temperature.attach(new Chauffage(temperature));
        temperature.attach(new Rideau(temperature));
        temperature.attach(new Climatisation(temperature));
        temperature.setTemp(20);
        temperature.setTemp(45);
    }    
}
