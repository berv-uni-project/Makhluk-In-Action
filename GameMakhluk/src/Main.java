import java.io.IOException;
import java.util.Scanner;

/**
 * @author M. Az-zahid Adhitya Silparensi-13514095
 */
public class Main {
    /**
     * untuk menghilangkan magic number checkstyle.
    **/
    private static final int MAGIC1 = 20;
    /**
     * untuk menghilangkan magic number checkstyle.
    **/
    private static final int MAGIC2 = 50;

    /**
     * Main program.
     * @param args sebagai masukan argumen yang diinginkan
     * @throws IOException
     * @throws InterruptedException
     */
    public static void main(
        final String[] args) throws IOException, InterruptedException {
        int u = MAGIC1;
        int max = MAGIC2;
            new ProcessBuilder("cmd", "/c", "cls").
                    inheritIO().start().waitFor();
            boolean stop = false;
            while (!stop) {
                    System.out.println("Apakah anda ingin membuat ukuran "
                            + "field sendiri? (Y/N)");
                    char c;
                    Scanner sn = new Scanner(System.in);
                    c = sn.next().charAt(0);
                    if (c == 'Y') {
                            System.out.print("Masukkan ukuran field : ");
                            u = sn.nextInt();
                            System.out.println();
                            System.out.print("Masukkan maksimal makhluk : ");
                            max = sn.nextInt();
                            System.out.println();
                            stop = true;
                    } else if (c == 'N') {
                            u = MAGIC1;
                            max = MAGIC2;
                            stop = true;
                    } else {
                            System.out.println("Masukan Salah Tolong Ulangi!");
                    }
            }
            //Menciptakan objek Control
            ControlCommand p = new ControlCommand(u, u, max);
            new KeyListenerForMe("Key Listener POKEMAN", p);
            p.start();
    }
}
