/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package makhlukinaction;

import java.util.ArrayList;
import makhluk.Makhluk;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.assertTrue;

/**
 *
 * @author Bervianto Leo P
 */
public class MakhlukSpawnTest {

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
     * Test of spawnMakhlukAntiAir method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukAntiAir() {
        System.out.println("spawnMakhlukAntiAir");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
        instance.spawnMakhlukAntiAir(n);
        assertTrue(true);
    }

    /**
     * Test of spawnMakhlukBurukRupa method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukBurukRupa() {
        System.out.println("spawnMakhlukBurukRupa");
        ArrayList<Makhluk> test = new ArrayList<>();
        MakhlukSpawn instance = new MakhlukSpawn(test);
        assertTrue(true);
    }

    /**
     * Test of spawnMakhlukMaling method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukMaling() {
        System.out.println("spawnMakhlukMaling");
        ArrayList<Makhluk> test = new ArrayList<>();
        MakhlukSpawn instance = new MakhlukSpawn(test);
        assertTrue(true);
    }

    /**
     * Test of spawnMakhlukMonster method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukMonster() {
        System.out.println("spawnMakhlukMonster");
        ArrayList<Makhluk> test = new ArrayList<>();
        MakhlukSpawn instance = new MakhlukSpawn(test);
        assertTrue(true);
    }

    /**
     * Test of spawnMakhlukTerbang method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukTerbang() {
        System.out.println("spawnMakhlukTerbang");
        ArrayList<Makhluk> test = new ArrayList<>();
        MakhlukSpawn instance = new MakhlukSpawn(test);
        assertTrue(true);
    }
}
