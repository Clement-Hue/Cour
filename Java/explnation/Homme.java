public class Homme {
    Animal animal;

   public Homme(Animal animal) {
        this.animal = animal;
   }

   public void promene() {
       System.out.println("je promene mon " + animal.toString());
   }
}
