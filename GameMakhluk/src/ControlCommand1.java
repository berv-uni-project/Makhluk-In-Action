import java.io.FileNotFoundException;
import java.util.Random;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Bervianto Leo P - 13514047
 * */

public class ControlCommand {
    /** cell sebagai penyimpan kumpulan makhluk. */
    private final HimpMakhluk[][] cell;
    /** nTotalMakhluk jumlah total makhluk. */
    private int nTotalMakhluk;
    /** panjang sebagai status panjang petak. */
    private final int panjang;
    /** lebar sebagai status lebar petak. */
    private final int lebar;
    /** maxTotalMakhluk sebagai status jumlah maks makhluk yg diperbolehkan. */
    private static int maxTotalMakhluk;
    /** creature sebagai status makhluk apa saja yang ada pada petak. */
    private final Makhluk[] creature;
    /** Sebagai status pause. */
    private boolean pause;
    /** Sebagai status keluar. */
    private final boolean exit;
    /** Sebagai status screenshot. */
    private boolean screenshot;
    /** Sebagai status step-by-step. */
    private boolean step;
    /** Sebagai status spawn. */
    private boolean spawn;
    /** Jumlah Maksimum Makhluk Default. */
    private final int defaultMaxTotalMakhluk = 30;
    /** Panjang Default. */
    private final int defaultPanjang = 10;
    /** Lebar Default. */
    private final int defaultLebar = 10;
    /** Konstruktor dengan nilai default
     * panjang = 10
     * lebar = 10
     * Maksimum Makhluk = 30.
     * */
    public ControlCommand() {
        maxTotalMakhluk = defaultMaxTotalMakhluk;
        panjang = defaultPanjang;
        lebar = defaultLebar;
        cell = new HimpMakhluk[panjang][lebar];
        for (int i = 0; i < this.panjang; i++) {
            for (int j = 0; j < this.panjang; j++) {
                cell[i][j] = new HimpMakhluk();
            }
        }
        creature = new Makhluk[maxTotalMakhluk];
        pause = false;
        exit = false;
        screenshot = false;
        step = false;
        spawn = false;
    }
    /**
     * Konstruktor dengan maksimum makhluk = panjang * lebar.
     * @param inpanjang sebagai inisialisasi panjang dari suatu petak
     * @param inlebar sebagai inisialisasi lebar dari suatu petak
     * */
    public ControlCommand(final int inpanjang, final int inlebar) {
        maxTotalMakhluk = inpanjang * inlebar;
        panjang = inpanjang;
        lebar = inlebar;
        cell = new HimpMakhluk[this.panjang][this.lebar];
        for (int i = 0; i < this.panjang; i++) {
            for (int j = 0; j < this.panjang; j++) {
                cell[i][j] = new HimpMakhluk();
            }
        }
        creature = new Makhluk[maxTotalMakhluk];
        pause = false;
        exit = false;
        screenshot = false;
        step = false;
        spawn = false;
    }
    /**
     * Konstruktor.
     * @param inpjg sebagai inisialisasi panjang dari suatu petak
     * @param inlbr sebagai inisialisasi lebar dari suatu petak
     * @param max sebagai maksimum makhluk yang boleh ada di petak
     * */
    public ControlCommand(final int inpjg, final int inlbr, final int max) {
        maxTotalMakhluk = max;
        this.panjang = inpjg;
        this.lebar = inlbr;
        cell = new HimpMakhluk[this.panjang][this.lebar];
        for (int i = 0; i < this.panjang; i++) {
            for (int j = 0; j < this.panjang; j++) {
                cell[i][j] = new HimpMakhluk();
            }
        }
        creature = new Makhluk[maxTotalMakhluk];
        pause = false;
        exit = false;
        screenshot = false;
        step = false;
        spawn = false;
    }
    /** Getter pause.
     * @return  */
    public final boolean getPause() {
        return pause;
    }
    /**
     * Fungsi mengembalikan nilai jumlah makhluk yang sedang ada di petak.
     * @return nTotalMakhluk Nilai jumlah makhluk yang sedang ada di petak
     * */
    public final int totalMakhlukinPetak() {
        return nTotalMakhluk;
    }
    /**
     * Fungsi mengembalikan nilai jlh maks makhluk yang dibolehkan pada petak.
     * @return maxTotalMakhluk Nilai jumlah makhluk yg dibolehkan pada petak
     * */
    public static int getMaxTotalMakhluk() {
        return maxTotalMakhluk;
    }
    /**
     * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak.
     * Makhluk akan diletakkan pada posisi acak
     * @return M sebagai kembalian makhluk apa yang akan dimunculkan
     * */
    public final Makhluk spawn() {
        final int type = 5;
        final int i = 1;
        Random rnd = new Random();
        int baris = rnd.nextInt(panjang - 1);
        int kolom = rnd.nextInt(lebar - 1);
        int tipe = rnd.nextInt(type) + 1;
        Makhluk m;
        switch (tipe) {
            case i:
                m = new MakhlukAntiAir(baris, kolom);
                break;
            case i + 1:
                m = new MakhlukBurukRupa(baris, kolom);
                break;
            case i + 2:
                m = new MakhlukMaling(baris, kolom);
                break;
            case i + i + 2:
                m = new MakhlukMonster(baris, kolom);
                break;
            case i + i + i + 2:
                m = new MakhlukTerbang(baris, kolom);
                break;
            default:
                m = new MakhlukAntiAir(baris, kolom);
        }
        cell[baris][kolom].addMakhluk(m);
        nTotalMakhluk++;
        return m;
    }
    /**
     * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak
     * Makhluk akan diletakkan pada posisi acak.
     * @param i parameter untuk lokasi x dalam petak
     * @param j parameter untuk lokasi y dalam petak
     * @param t parameter tipe makhluk yang akan ditampilkan
     * @return M sebagai kembalian makhluk apa yang akan dimunculkan
     * */
    public final Makhluk spawn(final int i, final int j, final int t) {
        final int x = 1;
        int baris = i;
        int kolom = j;
        int tipe = t;
        Makhluk m;
        switch (tipe) {
            case x:
                m = new MakhlukAntiAir(baris, kolom);
                break;
            case x + 1:
                m = new MakhlukBurukRupa(baris, kolom);
                break;
            case x + 2:
                m = new MakhlukMaling(baris, kolom);
                break;
            case x + x + 2:
                m = new MakhlukMonster(baris, kolom);
                break;
            case x + x + x + 2:
                m = new MakhlukTerbang(baris, kolom);
                break;
            default:
                m = new MakhlukAntiAir(baris, kolom);
        }
        cell[baris][kolom].addMakhluk(m);
        nTotalMakhluk++;
        return m;
    }
    /**
     * Prosedur mengecek perpindahan suatu makhluk dan memperbarui
     * status lokasi makhluk pada petak.
     * @param i lokasi yang ingin dipastikan (x) pada petak
     * @param j lokasi yang ingin dipastikan (y) pada petak
     * */
    public final void moveMakhluk(final int i, final int j) {
        boolean finish = false;
        if (!cell[i][j].isEmpty()) {
            while (cell[i][j].isOver()) {
                Makhluk n = cell[i][j].survFight();
                deleteMakhluk(n);
            }
            Makhluk m;
            do {
                m = cell[i][j].checkMoveMakhluk(i, j);
                if (m != null) {
                    int x = m.getX();
                    int y = m.getY();
                    int umur = m.getagenow();
                    int umurmax = m.getage();
if ((x < panjang) && (y < lebar) && (x >= 0) && (y >= 0) && (umur <= umurmax)) {
                        if (cell[x][y].isFull()) {
                            cell[x][y].addMakhluk(m);
                            Makhluk n = cell[x][y].survFight();
                            deleteMakhluk(n);
                        } else {
                            cell[x][y].addMakhluk(m);
                        }
                    } else {
                        deleteMakhluk(m);
                        m = cell[i][j].checkMoveMakhluk(i, j);
                        if (m == null) {
                            finish = true;
                        }
                    }
                }
            } while ((m != null) && (!exit));
        }
    }
    /**
     * Prosedur mengperbarui tampilan.
     * @param v sebagai pengontrol tampilan
     * */
    public final void updateWorld(final View v) {
        for (int i = 0; i < panjang; i++) {
            for (int j = 0; j < lebar; j++) {
                moveMakhluk(i, j);
            }
        }
        for (int i = 0; i < panjang; i++) {
            for (int j = 0; j < lebar; j++) {
                for(int k = 0; k < cell[i][j].getnMakhluk(); ++k) {
                    Makhluk r = cell[i][j].getMakhlukin(k);
                    v.ShowBentuk(r.gettype());
                }
		int n = cell[i][j].getnMakhluk();
                int max = cell[i][j].getMaxMakhluk();
                for (int k = n; k < max; k++) {
                    System.out.print(" ");
                    System.out.print("|");
                }
                System.out.println();
            }
        }
    }
    /**
     * Prosedur menghapus makhluk pada suatu petak.
     * @param m untuk identifikasi makhluk yang ingin dihapus
     * */
    public final void deleteMakhluk(final Makhluk m) {
        for (int i = 0; i < maxTotalMakhluk; i++) {
            if (m == creature[i]) {
                creature[i] = null;
		this.nTotalMakhluk--;
            }
        }
    }
    /** Prosedur untuk secara otomatis membangkitkan makhluk baru. */
    public final void autoSpawn() {
        int i = 0;
        while ((creature[i] != null) && (i < maxTotalMakhluk)) {
            i++;
            if (creature[i] == null) {
		creature[i] = spawn();
            }
	}
    }
    /**
     * Memulai sebuah program.
     */
    public final void start() {
        final int rnd1 = 4;
        final int rnd2 = 6;
        View v = new View();
        int delT = 0;
        Random rnd = new Random();
        int t =  rnd.nextInt(maxTotalMakhluk / rnd1) + (maxTotalMakhluk / rnd2);
        for (int i = 0; i < t; i++) {
            this.creature[i] = this.spawn();
            try {
                Thread.sleep(250);
            } catch (InterruptedException ex) {
                Thread.currentThread().interrupt();
            }
            try {
new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
            }
            final int complete = 100;
    float load = complete * i / (float) t;
            System.out.println("Now loading " + load + " %");
        }
        final int complete = 100;
        try {
    new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Now loading " + complete + " %");
        boolean stop = false;
        while ((totalMakhlukinPetak()) > 0 && !stop) {
            pause();
        exit();
        //screenshot
        screenshot(v);
        spawn(v);
        //step by step execution
        while (step) {
        int z = 0;
        final int batas = 10;
        final int batasdelT = 10000;
        while (z < batas) {
            if (delT == batasdelT) {
                delT = 0;
            }
            delT++;
                    step(delT);
                    ++z;
            }
        try {
new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
        }
        updateWorld(v);
        System.out.println();
        System.out.println("Step-by step execution 0.1 second");
        step = false;
        pause = true;
            pause();
        }
            try {
new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
            }
        updateWorld(v);
        System.out.println();
        final int batasdelT = 10000;
	if (delT == batasdelT) {
            delT = 0;
        }
            delT++;
            try {
            Thread.sleep(250);
            } catch (InterruptedException ex) {
               	Thread.currentThread().interrupt();
            }
                step(delT);
	}
        try {
new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
        }
	System.out.println();
	System.out.println("========================");
	System.out.println("Semua makhluk telah mati");
	System.out.println("      GAME OVER");
	System.out.println("========================");
	System.out.println();
	System.out.println("Press any key to exit");
	//Runtime.getRuntime().exec("pause>nul");
    }
    /**
     * Memberhentikan sementara program.
     */
    public final void pause() {
        if (pause) {
            System.out.println("Paused..... Press R in KeyListener to resume");
        }
        while (pause) {
            try {
                Thread.sleep(1);
            } catch (InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
    /**
     * Keluar dari program.
     */
    public final void exit() {
        if (exit) {
            System.out.println();
            System.out.println("===================================");
            System.out.println("Anda Telah Menekan ESC Untuk Keluar");
            System.out.println("            GAME OVER");
            System.out.println("===================================");
            System.out.println();
            //System.out.println("Press any key to exit");
            pause = true;
            pause();
            System.exit(0);
        }
    }
    /**
     * Menyimpan tampilan pada saat tertentu.
     * @param v sebagai viewer
     */
    public final void screenshot(final View v) {
        if (screenshot) {
            System.out.println("Screenshot telah disimpan!");
            printToFile(v);
            System.out.println("Press any key to continue");
            pause = true;
            pause();
            screenshot = false;
        }
    }
    /**
     * Menulis isi matriks ke dalam file.
     * @param v sebagai viewer
     */
    public final void printToFile(final View v) {
        try (PrintWriter f = new PrintWriter("screenshot.txt")) {
            for (int i = 0; i < panjang; i++) {
                for (int j = 0; j < lebar; j++) {
                    for (int k = 0; k < cell[i][j].getnMakhluk(); ++k) {
                        Makhluk r = cell[i][j].getMakhlukin(k);
                        f.print(v.getBentuk(r.gettype()));
                    }
                    int n = cell[i][j].getnMakhluk();
                    int max = cell[i][j].getMaxMakhluk();
                    for (int k = n; k < max; k++) {
                        f.print(" ");
                    }
                    f.print("|");
                }
                f.println();
            }   f.close();
        } catch (FileNotFoundException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * Memunculkan berbagai makhluk.
     * @param v sebagai viewer
     */
    public final void spawn(final View v) {
        while (spawn) {
            if (nTotalMakhluk < maxTotalMakhluk) {
                try {
new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
      } catch (IOException | InterruptedException ex) {
Logger.getLogger(ControlCommand.class.getName()).log(Level.SEVERE, null, ex);
                }
                autoSpawn();
                updateWorld(v);
                System.out.println("Telah Muncul Satu Makhluk Baru!");
                System.out.println("Press any key to continue");
            } else {
                System.out.println("Map Is FULL");
            }
            spawn = false;
            pause = true;
            pause();
        }
    }
    /**
     * Menggerakan step by step.
     * @param delT sebagai masukan deltaT saat itu
     */
    public final void step(final int delT) {
        for (int i = 0; i < maxTotalMakhluk; i++) {
            if (creature[i] != null) {
                creature[i].move();
            }
        }
        if (nTotalMakhluk < maxTotalMakhluk) {
            final int rand1 = 20;
            final int rand2 = 5;
            Random rand = new Random();
            if (delT % 2 == 0) {
                int x1 = rand.nextInt(rand1);
                int x2 = rand.nextInt(rand2);
		if (x1 < x2) {
                    autoSpawn();
		} else {
                    int x3 = rand.nextInt(rand2);
                    int x4 = rand.nextInt(rand1 / 2) + 2;
                    if (x3 >= x4) {
			autoSpawn();
                    }
                }
            }
        }
    }
}