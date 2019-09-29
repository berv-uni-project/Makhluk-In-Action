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
import static org.junit.Assert.*;

/**
 *
 * @author Bervianto Leo P
 */
public class MakhlukSpawnTest {
    
    public MakhlukSpawnTest() {
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
     * Test of spawnMakhlukAntiAir method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukAntiAir() {
        System.out.println("spawnMakhlukAntiAir");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
        instance.spawnMakhlukAntiAir(n);
    }

    /**
     * Test of spawnMakhlukBurukRupa method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukBurukRupa() {
        System.out.println("spawnMakhlukBurukRupa");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
    }

    /**
     * Test of spawnMakhlukMaling method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukMaling() {
        System.out.println("spawnMakhlukMaling");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
    }

    /**
     * Test of spawnMakhlukMonster method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukMonster() {
        System.out.println("spawnMakhlukMonster");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
    }

    /**
     * Test of spawnMakhlukTerbang method, of class MakhlukSpawn.
     */
    @Test
    public void testSpawnMakhlukTerbang() {
        System.out.println("spawnMakhlukTerbang");
        ArrayList<Makhluk> test = new ArrayList<>();
        int n = 2;
        MakhlukSpawn instance = new MakhlukSpawn(test);
    }
}
