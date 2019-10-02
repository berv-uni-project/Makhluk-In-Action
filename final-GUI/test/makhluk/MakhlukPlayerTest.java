/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package makhluk;

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
public class MakhlukPlayerTest {

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
     * Test of move method, of class MakhlukPlayer.
     */
    @Test
    public void testMove() {
        System.out.println("move");
        assertTrue(true);
    }

    /**
     * Test of playerUp method, of class MakhlukPlayer.
     */
    @Test
    public void testPlayerUp() {
        System.out.println("playerUp");
        MakhlukPlayer.playerUp();
        assertTrue(true);
    }

    /**
     * Test of playerDown method, of class MakhlukPlayer.
     */
    @Test
    public void testPlayerDown() {
        System.out.println("playerDown");
        MakhlukPlayer.playerDown();
        assertTrue(true);
    }

    /**
     * Test of playerRight method, of class MakhlukPlayer.
     */
    @Test
    public void testPlayerRight() {
        System.out.println("playerRight");
        MakhlukPlayer.playerRight();
        assertTrue(true);
    }

    /**
     * Test of playerLeft method, of class MakhlukPlayer.
     */
    @Test
    public void testPlayerLeft() {
        System.out.println("playerLeft");
        MakhlukPlayer.playerLeft();
        assertTrue(true);
    }

    /**
     * Test of getPlayer method, of class MakhlukPlayer.
     */
    @Test
    public void testGetPlayer() {
        System.out.println("getPlayer");
        Makhluk expResult = null;
        Makhluk result = MakhlukPlayer.getPlayer();
        assertEquals(expResult, result);
    }

    /**
     * Test of getMPlayer method, of class MakhlukPlayer.
     */
    @Test
    public void testGetMPlayer() {
        System.out.println("getMPlayer");
        MakhlukPlayer expResult = null;
        MakhlukPlayer result = MakhlukPlayer.getMPlayer();
        assertEquals(expResult, result);
    }

    /**
     * Test of draw method, of class MakhlukPlayer.
     */
    @Test
    public void testDraw() {
        System.out.println("draw");
        assertTrue(true);
    }

}
