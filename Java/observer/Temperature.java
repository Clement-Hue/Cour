import java.util.ArrayList;
import java.util.List;

class Temperature {
    List<Observer> observerList = new ArrayList<>();
    int temp = 0;
    public void attach(Observer observer) {
        observerList.add(observer);
    }
    public void detach(Observer observer) {
        observerList.remove(observer);
    }

    public int getTemp() {
        return temp;
    }

    public void setTemp(int temp) {
        this.temp = temp;
        System.out.println("la température est de " + temp +":");
        for (Observer observer: observerList) {
            observer.update();
        }
    }
}