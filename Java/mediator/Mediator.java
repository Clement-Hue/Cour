import java.util.ArrayList;
import java.util.List;

public abstract class Mediator {
    protected List<Colleague> lColleagues = new ArrayList<>();
   public abstract void send(Colleague sender ,String message);
   public void register(Colleague colleague) {
       this.lColleagues.add(colleague);
   }
   public void unregister(Colleague colleague) {
       this.lColleagues.remove(colleague);
   }
}
