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
public class ViewTest {

    public ViewTest() {
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
     * Test of ShowBentuk method, of class View.
     */
    @Test
    public void testShowBentuk() {
        System.out.println("ShowBentuk");
        View instance = new View();
        instance.showBentuk(1);
        instance.showBentuk(2);
        instance.showBentuk(3);
        instance.showBentuk(4);
        instance.showBentuk(5);
        // tidak dapat di assert karena tidak dapat dibandingkan (hanya berisi
        // System.out.println)
        // TODO review the generated test code and remove the default call to fail.
    }

    /**
     * Test of GetBentuk method, of class View.
     */
    @Test
    public void testGetBentuk() {
        System.out.println("GetBentuk");
        View instance = new View();
        char result = instance.getBentuk(1);
        assertEquals('*', result);
        assertEquals('%', instance.getBentuk(2));
        assertEquals('$', instance.getBentuk(3));
        assertEquals('@', instance.getBentuk(4));
        assertEquals('~', instance.getBentuk(5));
        // TODO review the generated test code and remove the default call to fail.

    }

}
