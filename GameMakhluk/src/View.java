
import javax.swing.JFrame;

/**
 * @author Bervianto Leo P - 13514047
 * */

public class View extends JFrame {
        /**
        * variabel untuk di dalam if (magic number).
        * */
        private static final int MAGIC1 = 3;
        /**
        * variabel untuk di dalam if (magic number).
        * */
        private static final int MAGIC2 = 4;
        /**
        * variabel untuk di dalam if (magic number).
        * */
        private static final int MAGIC3 = 5;

        /**
        * Prosedur menampilkan bentuk dengan suatu parameter.
        * @param a sebagai parameter untuk menampilkan sesuatu
        * */
        public final void showBentuk(final int a) {
            if (a == 1) {
                System.out.print('*');
            } else if (a == 2) {
                System.out.print('%');
            } else if (a == MAGIC1) {
                System.out.print('$');
            } else if (a == MAGIC2) {
                System.out.print('@');
            } else if (a == MAGIC3) {
                System.out.print('~');
            } else {
                System.out.print(' ');
            }
        }

        /**
        * fungsi mendapatkan bentuk dan mengembalikan bentuk.
        * @param a sebagai indikator untuk memberikan bentuk
        * @return bentuk hasil convert tipe
        * */
        public final char getBentuk(final int a) {
            if (a == 1) {
                return '*';
            } else if (a == 2) {
                return '%';
            } else if (a == MAGIC1) {
                return '$';
            } else if (a == MAGIC2) {
                return '@';
            } else if (a == MAGIC3) {
                return '~';
            } else {
                return ' ';
            }
        }
}
