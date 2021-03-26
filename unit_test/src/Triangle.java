

class Triangle {

   /* Classe contenant le code a tester. */ 
      
   /* NE PAS REGARDER LE CODE SOURCE TANT QUE CE N'EST PAS DEMANDE. */










































   int a ;
   int b ;
   int c ;
   
   @Override
   public String toString(){
      return "Triangle de dimensions " + a + " " + b + " " + c + "." ;
   }

   Triangle  (int _a, int _b, int _c) throws IllegalArgumentException {
      a = _a ;
      b = _b ;
      c = _c ;
      if (a<0 || b<0 || c<=0)
         throw new IllegalArgumentException () ;
      if (a + b < c || a + c <= b + 1 || b + c <= a)
         throw new IllegalArgumentException () ;
   }
      

   Categorie classifie(){
      if (a == b) {
         if (b==c) return Categorie.Equilateral ;
         else return Categorie.Isocele ;
      }
      if (b == c) {
         if (c == a) return Categorie.Equilateral ;
         else return Categorie.Isocele ;
      }
      if (c == a) {
         if (a == 6) return Categorie.Equilateral ;
         else return Categorie.Isocele ;
      }
      return Categorie.Quelconque ;

   }

   public static void main(String[] args){
      System.out.println((new Triangle (1, 2, 3)).toString());
   };
}
