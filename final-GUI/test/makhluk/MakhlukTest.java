/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package makhluk;

import java.awt.Graphics;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

/**
 *
 * @author Bervianto Leo P
 */
public class MakhlukTest {

    @BeforeClass
    public static void setUpClass() {
         // setup
    }

    @AfterClass
    public static void tearDownClass() {
        // remove
    }

    @Before
    public void setUp() {
         // another class setup
    }

    @After
    public void tearDown() {
         // another class tear down
    }

    /**
     * Test of getpowerlevel method, of class Makhluk.
     */
    @Test
    public void testGetpowerlevel() {
        System.out.println("getpowerlevel");
        Makhluk instance = new MakhlukImpl();
        int expResult = 0;
        int result = instance.getpowerlevel();
        assertEquals(expResult, result);
    }

    /**
     * Test of gettype method, of class Makhluk.
     */
    @Test
    public void testGettype() {
        System.out.println("gettype");
        Makhluk instance = new MakhlukImpl();
        int expResult = 0;
        int result = instance.gettype();
        assertEquals(expResult, result);
    }

    /**
     * Test of getX method, of class Makhluk.
     */
    @Test
    public void testGetX() {
        System.out.println("getX");
        Makhluk instance = new MakhlukImpl();
        int expResult = 0;
        int result = instance.getX();
        assertEquals(expResult, result);
    }

    /**
     * Test of getY method, of class Makhluk.
     */
    @Test
    public void testGetY() {
        System.out.println("getY");
        Makhluk instance = new MakhlukImpl();
        int expResult = 0;
        int result = instance.getY();
        assertEquals(expResult, result);
    }

    /**
     * Test of getAlive method, of class Makhluk.
     */
    @Test
    public void testGetAlive() {
        System.out.println("getAlive");
        Makhluk instance = new MakhlukImpl();
        boolean expResult = false;
        boolean result = instance.getAlive();
        assertEquals(expResult, result);
    }

    /**
     * Test of setX method, of class Makhluk.
     */
    @Test
    public void testSetX() {
        System.out.println("setX");
        int x1 = 0;
        Makhluk instance = new MakhlukImpl();
        instance.setX(x1);
        assertEquals(x1, instance.getX());
    }

    /**
     * Test of setY method, of class Makhluk.
     */
    @Test
    public void testSetY() {
        System.out.println("setY");
        int y1 = 0;
        Makhluk instance = new MakhlukImpl();
        instance.setY(y1);
        assertEquals(y1, instance.getY());
    }

    /**
     * Test of setType method, of class Makhluk.
     */
    @Test
    public void testSetType() {
        System.out.println("setType");
        int type1 = 0;
        Makhluk instance = new MakhlukImpl();
        instance.setType(type1);
        assertEquals(type1, instance.gettype());
    }

    /**
     * Test of setPowerLevel method, of class Makhluk.
     */
    @Test
    public void testSetPowerLevel() {
        System.out.println("setPowerLevel");
        int pwl = 0;
        Makhluk instance = new MakhlukImpl();
        instance.setPowerLevel(pwl);
        assertEquals(pwl, instance.getpowerlevel());
    }

    /**
     * Test of setAlive method, of class Makhluk.
     */
    @Test
    public void testSetAlive() {
        System.out.println("setAlive");
        boolean isAlive = false;
        Makhluk instance = new MakhlukImpl();
        instance.setAlive(isAlive);
        assertEquals(isAlive, instance.getAlive());
    }

    /**
     * Test of setDead method, of class Makhluk.
     */
    @Test
    public void testSetDead() {
        System.out.println("setDead");
        Makhluk instance = new MakhlukImpl();
        instance.setDead();
        assertEquals(false, instance.getAlive());
    }

    /**
     * Test of fight method, of class Makhluk.
     */
    @Test
    public void testFight() {
        System.out.println("fight");
        Makhluk a = new MakhlukImpl();
        Makhluk instance = new MakhlukImpl();
        instance.fight(a);
        assertEquals(false,instance.getAlive());
    }

    /**
     * Test of draw method, of class Makhluk.
     */
    @Test
    public void testDraw() {
        System.out.println("draw");
        assertTrue(true);
    }

    public class MakhlukImpl extends Makhluk {

        public void draw(Graphics g) {
        }
    }
    
}
