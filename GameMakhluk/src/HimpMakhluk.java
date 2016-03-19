
import java.util.ArrayList;
import java.util.List;

//import java.util.*;

/**
 * @author Joshua Salimin - 13514001
 */
public class HimpMakhluk {

    /**.
     * MaxMakhluk sebagai batas makhluk yang diperbolehkan dalam himpunan makhlu
     * k
     * al sebagai penyimpan himpunan makhluk
     */
    private final int maxMakhluk = 1;
   /**.
    * List yang menyimpan makhluk
    */
    private List<Makhluk> al;
    /**.
     * Konstruktor kelas HimpMakhluk
     */
    public HimpMakhluk() {
        al = new ArrayList<Makhluk>();
    }
    /**.
     * Sebuah prosedur untuk menambahkan sebuah Makhluk ke dalam ArrayList
     * @param m merupakan Makhluk yang akan ditambahkan ke dalam ArrayList
     */
    public final void addMakhluk(final Makhluk m) {
        al.add(m);
    }
    /**.
     * Sebuah fungsi yang mengembalikan Makhluk yang dihapus dari
     * ArrayList dimana Makhluk tersebut memiliki powerlevel yang lebih kecil
     * @return Makhluk merupakan Makhluk yang dihapus dari ArrayList
     */
    public final Makhluk survFight() {
        int temppower = al.get(0).powerlevel;
        int id = al.get(0).type;
        int idxfound = 0;
        for (int j = 0; j < al.size(); ++j) {
            if (temppower < al.get(j).powerlevel) {
                temppower = al.get(j).powerlevel;
                idxfound = j;
            }
        }
    return deleteMakhluk(al.get(idxfound));
    }
    /**.
     * Sebuah fungsi yang akan mencari Makhluk dan menghapus Makhluk
     * tersebut dari ArrayList
     * @param m merupakan masukan sebuah Makhluk yang akan dihapus
     * @return Makhluk merupakan makhluk yang dihapus
     */
    public final Makhluk deleteMakhluk(final Makhluk m) {
        boolean found  = false;
        if (al.size() != 0) {
            int i = 0;
            while (i < al.size() && !found) {
                if (al.get(i).type == m.type) {
                    found = true;
                } else {
                    ++i;
                }
            }
            if (found) {
                Makhluk s = al.get(i);
                al.remove(i);
                return s;
            } else {
                return null;
            }
        } else {
            return null;
        }
    }
    /**.
     * sebuah fungsi yang mengembalikan boolean apakah ArrayList penuh
     * atau tidak
     * @return true/false boolean apakah true atau false
     */
    public final boolean isFull() {
        return al.size() == maxMakhluk;
    }
    /**.
     *sebuah fungsi yang mengembalikan Makhluk di indeks ke i
     * @param i merupakan posisi indeks
     * @return al.get(i) Makhluk yang merupakan di cari
     */
    public final Makhluk getMakhlukin(final int i) {
        return al.get(i);
    }
    /**.
     * Sebuah fungsi yang mengembalikan integer, banyaknya Makhluk
     * dalam ArrayList
     * @return al.size() size daripada ArrayList
     */
    public final int getnMakhluk() {
        return al.size();
    }
    /**.
     * Sebuah fungsi yang mengembalikan integer yaitu banyaknya
     * Maksimum Makhluk yang dapat ditampung dalam satu ArrayList
     * @return MaxMakhluk
     */
    public final int getMaxMakhluk() {
        return maxMakhluk;
    }
    /**.
     * Sebuah fungsi yang mengembalikan boolean apakah size dari
     * ArrayList lebih besar dari Maksimum Makhluk yang dapat ditampungg
     * @return true/false
     */
    public final boolean isOver() {
        return al.size() > maxMakhluk;
    }
    /**.
     * Sebuah fungsi yang mengembalikan boolean dan mengecek
     * apakah ArrayList kosong atau tidak
     * @return true/false
     */
    public final boolean isEmpty() {
        return al.size() == 0;
    }
    /**.
     * Sebuah fungsi yang mengembalikan Makhluk dan menghapus
     * Makhluk dari ArrayList jika Makhluk tersebut sudah pindah
     * @param x absis posisi dari Makhluk
     * @param y ordinat posisi dari Makhluk
     * @return Makhluk yang sudah berpindah
     */
    public final Makhluk checkMoveMakhluk(final int x, final int y) {
        //dianggap dalam suatu array hanya terdapat 1 makhluk
        Makhluk m = null;
        int i = 0;
        int px, py;
        boolean end = false;
        while (i < al.size() && !end) {
            px = al.get(i).x;
            py = al.get(i).y;
            if (px != x || py != y) {
                m = deleteMakhluk(al.get(i));
                end = true;
            } else {
                ++i;
            }
        }
        return m;
    }
}
