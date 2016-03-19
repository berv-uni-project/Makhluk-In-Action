/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Joshua - 13514001
 */
public class HewanThread extends Thread {
    /** m merupakan sebuah Makhluk. */
    private Makhluk m;
    /** cc merupakan sebuah ControlCommand. */
    private ControlCommand cc;
    /** Konstruktor dengan parameter Makhluk.
     @param m1 menerima makhluk tertentu
     @param cc1 menerima kelas ControlCommand*/
    HewanThread(final Makhluk m1, final ControlCommand cc1) {
        this.m = m1;
        this.cc = cc1;
    }

    @Override
    /** Prosedur menjalankan Thread. */
    public void run() {
        
    }
}
