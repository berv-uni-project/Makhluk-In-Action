package makhlukinaction;

import makhluk.MakhlukAntiAir;
import makhluk.MakhlukBurukRupa;
import makhluk.MakhlukMaling;
import makhluk.MakhlukMonster;
import makhluk.MakhlukTerbang;
import makhluk.Makhluk;
import java.util.ArrayList;

/**
 * @author Joshua
 */
public class MakhlukSpawn {
    /** myarraylist merupakan sebuah arral list Makhluk. */
    private ArrayList<Makhluk> myarraylist;
    /** Konstruktor MakhlukSpawn.
     @param al1 sebuah arraylist makhluk */
    public MakhlukSpawn(final ArrayList<Makhluk> al1) {
        myarraylist = al1;
    }
    /**
     * Prosedur untuk menciptakan makhluk anti air sebanyak n.
     * @param n Jumlah makhluk yang akan dispawn
     */
    public final void spawnMakhlukAntiAir(final int n) {
        for (int i = 0; i <  n; i++) {
            Makhluk m = new MakhlukAntiAir();
            myarraylist.add(m);
        }
    }
    /**
     * Prosedur untuk menciptakan makhluk buruk rupa sebanyak n.
     * @param n Jumlah makhluk yang akan dispawn
     */
    public final void spawnMakhlukBurukRupa(final int n) {
        for (int i = 0; i <  n; i++) {
            Makhluk m = new MakhlukBurukRupa();
            myarraylist.add(m);
        }
    }
    /**
     * Prosedur untuk menciptakan makhluk maling sebanyak n.
     * @param n Jumlah makhluk yang akan dispawn
     */
    public final void spawnMakhlukMaling(final int n) {
        for (int i = 0; i <  n; i++) {
            Makhluk m = new MakhlukMaling();
            myarraylist.add(m);
        }
    }
    /**
     * Prosedur untuk menciptakan makhluk monster sebanyak n.
     * @param n Jumlah makhluk yang akan dispawn
     */
    public final void spawnMakhlukMonster(final int n) {
        for (int i = 0; i <  n; i++) {
            Makhluk m = new MakhlukMonster();
            myarraylist.add(m);
        }
    }
    /**
     * Prosedur untuk menciptakan makhluk terbang sebanyak n.
     * @param n Jumlah makhluk yang akan dispawn
     */
    public final void spawnMakhlukTerbang(final int n) {
        for (int i = 0; i <  n; i++) {
            Makhluk m = new MakhlukTerbang();
            myarraylist.add(m);
        }
    }
}
