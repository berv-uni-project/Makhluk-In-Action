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
import makhlukinaction.model.*;
import static org.junit.Assert.*;

/**
 *
 * @author Joshua
 */
public class HimpMakhlukTest {

    public HimpMakhlukTest() {
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
     * Test of AddMakhluk method, of class HimpMakhluk.
     */
    @Test
    public void testAddMakhluk() {
        System.out.println("AddMakhluk");
        Makhluk M = new MakhlukAntiAir();
        HimpMakhluk instance = new HimpMakhluk();
        instance.addMakhluk(M);
        // TODO review the generated test code and remove the default call to fail.
        System.out.println("Tipe Makhluk Test: " + instance.getMakhlukin(0).getType());
        assertEquals(instance.getMakhlukin(0), M);
        assertEquals(1, instance.getMakhlukin(0).getType());
        Makhluk M2 = new MakhlukMaling();
        instance.addMakhluk(M2);
        System.out.println("Tipe Makhluk Test2: " + instance.getMakhlukin(1).getType());
        assertEquals(instance.getMakhlukin(1), M2);
        System.out.println("Sucess");
    }

    /**
     * Test of SurvFight method, of class HimpMakhluk.
     */
    @Test
    public void testSurvFight() {
        System.out.println("SurvFight");
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukMaling();
        instance.addMakhluk(M);
        instance.addMakhluk(M2);
        Makhluk Mhasil = instance.survFight();
        System.out.println("Isi ArrayList: " + instance.getMakhlukin(0).getType());
        System.out.println("Tipe Makhluk SurvFight: " + Mhasil.getType());
        assertEquals(Mhasil.getType(), M2.getType());
        System.out.println("Sucess");
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of DeleteMakhluk method, of class HimpMakhluk.
     */
    @Test
    public void testDeleteMakhluk() {
        System.out.println("DeleteMakhluk");
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukMaling();
        instance.addMakhluk(M);
        instance.addMakhluk(M2);
        instance.deleteMakhluk(M);
        System.out.println(instance.getNMakhluk());
        assertEquals(1, instance.getNMakhluk());
        System.out.println("Sucess");
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of isFull method, of class HimpMakhluk.
     */
    @Test
    public void testIsFull() {
        System.out.println("isFull");
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        instance.addMakhluk(M);
        boolean expResult = true;
        boolean result = instance.isFull();
        assertEquals(expResult, result);
        System.out.println("Sucess");
        // maksimal penuh adalah 1
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of GetMakhlukin method, of class HimpMakhluk.
     */
    @Test
    public void testGetMakhlukin() {
        System.out.println("GetMakhlukin");
        int i = 1;
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        instance.addMakhluk(M);
        // mengetes apakah benar yang di return adalah makhluk anti air dengan type =1
        assertEquals(1, instance.getMakhlukin(0).getType());
        System.out.println("Sucess");
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of GetnMakhluk method, of class HimpMakhluk.
     */
    @Test
    public void testGetnMakhluk() {
        System.out.println("GetnMakhluk");
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukMaling();
        instance.addMakhluk(M);
        instance.addMakhluk(M2);
        int expResult = 2;
        int result = instance.getNMakhluk();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of GetMaxMakhluk method, of class HimpMakhluk.
     */
    @Test
    public void testGetMaxMakhluk() {
        System.out.println("GetMaxMakhluk");
        HimpMakhluk instance = new HimpMakhluk();
        int expResult = 0;
        int result = instance.getMaxMakhluk();
        // 1 merupakan nilai maksimum pada arraylist
        assertEquals(1, result);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of isOver method, of class HimpMakhluk.
     */
    @Test
    public void testIsOver() {
        System.out.println("isOver");
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        Makhluk M2 = new MakhlukMaling();
        instance.addMakhluk(M);
        instance.addMakhluk(M2);
        boolean expResult = true;
        boolean result = instance.isOver();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of isEmpty method, of class HimpMakhluk.
     */
    @Test
    public void testIsEmpty() {
        System.out.println("isEmpty");
        HimpMakhluk instance = new HimpMakhluk();
        boolean expResult = true;
        boolean result = instance.isEmpty();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of checkMoveMakhluk method, of class HimpMakhluk.
     */
    @Test
    public void testCheckMoveMakhluk() {
        System.out.println("checkMoveMakhluk");
        // untuk di test bahwa makhluk telah berpindah
        int x = 1;
        int y = 1;
        HimpMakhluk instance = new HimpMakhluk();
        Makhluk M = new MakhlukAntiAir();
        instance.addMakhluk(M);
        Makhluk result = instance.checkMoveMakhluk(x, y);
        assertEquals(M, result);
        // TODO review the generated test code and remove the default call to fail.
    }

}
