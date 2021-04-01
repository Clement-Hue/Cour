import static org.junit.Assert.*;

import org.junit.Test;


public class TestJunit {


    @Test
    public void shouldBeEquilateral() {
        Triangle tri = new Triangle(3,3,3);
        assertEquals(tri.classifie(), Categorie.Equilateral);
    }
    @Test
    public void shouldBeIsocele() {
        Triangle tri = new Triangle(4,4,7);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }
    @Test
    public void shouldBeQuelconque() {
        Triangle tri = new Triangle(7,5,9);
        assertEquals(tri.classifie(), Categorie.Quelconque);
    }

    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle() {
        Triangle tri = new Triangle(-5,-2,8);
    }

    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle2() {
        Triangle tri = new Triangle(4,4,9);
    }

    @Test
    public void shouldCreateTriangle() {
        Triangle tri = new Triangle(4,4,5);
    }

    @Test
    public void shouldBeIsocele2() {
        Triangle tri = new Triangle(4,4,8);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }

    @Test
    public void shouldBeQuelconque2() {
        Triangle tri = new Triangle(1,2,3);
        assertEquals(tri.classifie(), Categorie.Quelconque);
    }

    @Test
    public void shouldCreateTriangle3() {
        Triangle tri = new Triangle(8,4,4);
    }
    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle3() {
        Triangle tri = new Triangle(4,3,8);
    }
    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle4() {
        Triangle tri = new Triangle(0,0,0);
    }
    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle5() {
        Triangle tri = new Triangle(-4,8,2);
    }
    @Test(expected = Exception.class)
    public void shouldNotCreateTriangle6() {
        Triangle tri = new Triangle(3,3,7);
    }

    @Test
    public void shouldCreateTriangle4() {
        Triangle tri = new Triangle(4,4,8);
    }

    @Test
    public void shouldBeEquilateral5() {
        Triangle tri = new Triangle(3,3,3);
        assertEquals(tri.classifie(), Categorie.Equilateral);
    }
    @Test
    public void shouldBeEquilateral6() {
        Triangle tri = new Triangle(4,4,4);
        assertEquals(tri.classifie(), Categorie.Equilateral);
    }
    @Test
    public void shouldBeIsocele3() {
        Triangle tri = new Triangle(3,3,5);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }
    @Test
    public void shouldBeIsocele4() {
        Triangle tri = new Triangle(5,3,3);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }
    @Test
    public void shouldBeIsocele5() {
        Triangle tri = new Triangle(6,2,6);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }
    @Test
    public void shouldBeIsocele7() {
        Triangle tri = new Triangle(8,6,6);
        assertEquals(tri.classifie(), Categorie.Isocele);
    }
    @Test
    public void shouldBeQuelconque3() {
        Triangle tri = new Triangle(4,5,6);
        assertEquals(tri.classifie(), Categorie.Quelconque);
    }

}