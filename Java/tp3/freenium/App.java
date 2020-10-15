public class App {
   public static void main(String[] args) {
       User []listUser = new Free[5];
       for (int i = 0; i< listUser.length; i++) {
           listUser[i] = new Free();
            System.out.println("nom:" + listUser[i].getNom());
       }
   } 
}