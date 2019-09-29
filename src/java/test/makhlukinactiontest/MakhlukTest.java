package makhlukinactiontest;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import makhlukinaction.*;
import static org.junit.Assert.*;

/**
 *
 * @author Joshua
 */
public class MakhlukTest {

    public MakhlukTest() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    /**
     * Test of move method, of class Makhluk.
     */
    @Test
    public void testMove() {
        System.out.println("move");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        // hanya untuk junit
        M.deltaT = 0;
        M2.deltaT = 0;
        M3.deltaT = 0;
        M4.deltaT = 0;
        M5.deltaT = 0;
        M.move();
        M2.move();
        M3.move();
        M4.move();
        M5.move();
        System.out.println(M.getX() + " " + M.getY());
        System.out.println(M2.getX() + " " + M.getY());
        System.out.println(M3.getX() + " " + M.getY());
        System.out.println(M4.getX() + " " + M.getY());
        System.out.println(M5.getX() + " " + M.getY());
        // TODO review the generated test code and remove the default call to fail.
        // tidak dapat melakukan assert karena fungsi random namun sudah dicek dapat
        // melakukan random

    }

    /**
     * Test of getpowerlevel method, of class Makhluk.
     */
    @Test
    public void testGetpowerlevel() {
        System.out.println("getpowerlevel");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getPowerLevel(), 60);
        assertEquals(M2.getPowerLevel(), 80);
        assertEquals(M3.getPowerLevel(), 75);
        assertEquals(M4.getPowerLevel(), 100);
        assertEquals(M5.getPowerLevel(), 70);
        // TODO review the generated test code and remove the default call to fail.\
    }

    /**
     * Test of getage method, of class Makhluk.
     */
    @Test
    public void testGetage() {
        System.out.println("getage");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getAge(), 90);
        assertEquals(M2.getAge(), 80);
        assertEquals(M3.getAge(), 40);
        assertEquals(M4.getAge(), 60);
        assertEquals(M5.getAge(), 30);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of getagenow method, of class Makhluk.
     */
    @Test
    public void testGetagenow() {
        System.out.println("getagenow");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getAgeNow(), 0);
        assertEquals(M2.getAgeNow(), 0);
        assertEquals(M3.getAgeNow(), 0);
        assertEquals(M4.getAgeNow(), 0);
        assertEquals(M5.getAgeNow(), 0);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of getdeltaT method, of class Makhluk.
     */
    @Test
    public void testGetdeltaT() {
        System.out.println("getdeltaT");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        int a = (int) M.getDeltaT();
        int b = (int) M2.getDeltaT();
        int c = (int) M3.getDeltaT();
        int d = (int) M4.getDeltaT();
        int e = (int) M5.getDeltaT();
        System.out.println(a + " " + b + " " + c + " " + d + " " + e);
        assertEquals(a, 8);
        assertEquals(b, 7);
        assertEquals(c, 5);
        assertEquals(d, 10);
        assertEquals(e, 3);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of gettype method, of class Makhluk.
     */
    @Test
    public void testGettype() {
        System.out.println("gettype");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getType(), 1);
        assertEquals(M2.getType(), 2);
        assertEquals(M3.getType(), 3);
        assertEquals(M4.getType(), 4);
        assertEquals(M5.getType(), 5);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of getX method, of class Makhluk.
     */
    @Test
    public void testGetX() {
        System.out.println("getX");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getX(), 0);
        assertEquals(M2.getX(), 0);
        assertEquals(M3.getX(), 0);
        assertEquals(M4.getX(), 0);
        assertEquals(M5.getX(), 0);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of getY method, of class Makhluk.
     */
    @Test
    public void testGetY() {
        System.out.println("getY");
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukBurukRupa();
        Makhluk M3 = new MakhlukMaling();
        Makhluk M4 = new MakhlukMonster();
        Makhluk M5 = new MakhlukTerbang();
        assertEquals(M.getY(), 0);
        assertEquals(M2.getY(), 0);
        assertEquals(M3.getY(), 0);
        assertEquals(M4.getY(), 0);
        assertEquals(M5.getY(), 0);
        // TODO review the generated test code and remove the default call to fail.
    }

    public class MakhlukImpl extends Makhluk {

        public void move() {
        }
    }

}
