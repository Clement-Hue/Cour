public class VisiteurFR extends Visiteur{
    @Override
    public void visit(Musee musee) {
       System.out.println("je visite un musee |"+ musee.affiche());
   }  

   @Override
   public void visit(MuseeRegional musee) {
       System.out.println("je visite un musee regional ["+musee.affiche());
   }
}
