public class TestTriangle {

    public static void main(String[] args) {
        testBoiteNoir();
        testBoiteBlanche();
    }

    private static void testBoiteBlanche() {
       System.out.println("test boite blanche");
       testShouldNotCreateTriangle(-4,8,2);
       testShouldNotCreateTriangle(3,3,7);
       testShouldCreateTriangle(4,4,8);
       testShouldBeEquilateral(3,3,3);
       testShouldBeEquilateral(4,4,4);
       testShouldBeIsocele(3,3,5);
       testShouldBeIsocele(5,3,3);
       testShouldBeIsocele(6,2,6);
       testShouldBeIsocele(8,6,8);
       testShouldBeQuelconque(4,5,6);
    }

    private static void testBoiteNoir() {
        System.out.println("test boite noir");
        testShouldCreateTriangle(3, 3, 3);
        testShouldCreateTriangle(8, 4, 4);
        testShouldBeEquilateral(3, 3, 3);
        testShouldBeIsocele(4, 4, 7);
        testShouldBeQuelconque(7, 5, 9);
        testShouldBeIsocele(4, 4, 8);
        testShouldNotCreateTriangle(-5, -2, -8);
        testShouldNotCreateTriangle(4, 4, 9);
        testShouldCreateTriangle(4, 4, 5);
        testShouldCreateTriangle(4, 4, 8);
        testShouldNotCreateTriangle(4, 3, 8);
        testShouldNotCreateTriangle(0, 0, 0);
        testShouldBeQuelconque(1,2,3);
    }

    private static void testShouldNotCreateTriangle(int a, int b, int c) {
        try {
            Triangle tr = new Triangle(a, b, c);
            System.out.println("le triangle n'est pas créé a:" + a +" b:"+b +" c:" + c +" " + false);
        } catch (Exception e) {
            System.out.println("le triangle n'est pas créé a:" + a +" b:"+b +" c:" + c +" " + true);
        }
    }
    private static void testShouldBeIsocele(int a, int b, int c) {
        Triangle tr1 = new Triangle(a, b, c);
        System.out.println("le triangle est isocèle a: " +a +" b:" +b + " c:" + c + " "  + (tr1.classifie() == Categorie.Isocele));
    }
    private static void testShouldBeEquilateral(int a, int b, int c) {
        Triangle tr1 = new Triangle(a, b, c);
        System.out.println("le triangle est équilatéral a: " +a +" b:" +b + " c:" + c + " "  + (tr1.classifie() == Categorie.Equilateral));
    }
    private static void testShouldBeQuelconque(int a, int b, int c) {
        Triangle tr1 = new Triangle(a, b, c);
        System.out.println("le triangle est quelconque a: " +a +" b:" +b + " c:" + c + " "  + (tr1.classifie() == Categorie.Quelconque));
    }


    private static void testShouldCreateTriangle(int a, int b, int c) {
        try {
            Triangle triangle = new Triangle(a, b, c);
            System.out.println("le triangle est créé a:" +a + " b:" +b + " c:" + c + " " + true);
        } catch (Exception e) {
            System.out.println("le triangle est créé a:" +a + " b:" +b + " c:" + c + " " + false);
        }
    }

}
