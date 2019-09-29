package makhlukinaction;

import java.io.FileNotFoundException;
import java.util.Random;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import makhlukinaction.model.*;

/**
 * @author Bervianto Leo P - 13514047
 */

public class ControlCommand {
	/**
	 * Cell sebagai penyimpan kumpulan makhluk, setiap sel dapat menyimpan banyak
	 * makhluk dan akan dipertarungkan nTotalMakhluk sebagai status jumlah makhluk
	 * yang sedang ada pada petak panjang sebagai status panjang petak lebar sebagai
	 * status lebar petak MaxTotalMakhluk sebagai status jumlah maksimum makhluk
	 * yang diperbolehkan (membatasi pertumbuhan makhluk) Creature sebagai status
	 * makhluk apa saja yang ada pada petak
	 */
	private final HimpMakhluk[][] cells;
	private int nTotalMakhluk;
	private final int panjang;
	private final int lebar;
	private final int maxTotalMakhluk;
	private final Makhluk[] creature;

	/**
	 * Sebagai status pause
	 */
	public boolean pause;

	/**
	 * Sebagai status keluar
	 */
	public boolean exit;

	/**
	 * Sebagai status screenshot
	 */
	public boolean screenshot;

	/**
	 * Sebagai status step-by-step
	 */
	public boolean step;

	/**
	 * Sebagai status spawn
	 */
	public boolean spawn;

	/**
	 * Konstruktor dengan nilai default panjang = 10 lebar = 10 Maksimum Makhluk =
	 * 30
	 */
	public ControlCommand() {
		maxTotalMakhluk = 30;
		this.panjang = 10;
		this.lebar = 10;

		cells = new HimpMakhluk[panjang][lebar];
		for (int i = 0; i < this.panjang; i++) {
			for (int j = 0; j < this.panjang; j++) {
				cells[i][j] = new HimpMakhluk();
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
	 * Konstruktor
	 * 
	 * @param _panjang sebagai inisialisasi panjang dari suatu petak
	 * @param _lebar   sebagai inisialisasi lebar dari suatu petak Maksimum makhluk
	 *                 = panjang * lebar
	 */
	public ControlCommand(int _panjang, int _lebar) {
		maxTotalMakhluk = _panjang * _lebar;
		this.panjang = _panjang;
		this.lebar = _lebar;

		cells = new HimpMakhluk[this.panjang][this.lebar];
		for (int i = 0; i < this.panjang; i++) {
			for (int j = 0; j < this.panjang; j++) {
				cells[i][j] = new HimpMakhluk();
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
	 * Konstruktor
	 * 
	 * @param _panjang sebagai inisialisasi panjang dari suatu petak
	 * @param _lebar   sebagai inisialisasi lebar dari suatu petak
	 * @param max      sebagai maksimum makhluk yang boleh ada di petak
	 */
	public ControlCommand(int _panjang, int _lebar, int max) {
		maxTotalMakhluk = max;
		this.panjang = _panjang;
		this.lebar = _lebar;

		cells = new HimpMakhluk[this.panjang][this.lebar];
		for (int i = 0; i < this.panjang; i++) {
			for (int j = 0; j < this.panjang; j++) {
				cells[i][j] = new HimpMakhluk();
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
	 * Sebagai fungsi mengembalikan nilai jumlah makhluk yang sedang ada di petak
	 * 
	 * @return nTotalMakhluk sebagai nilai kembalian jumlah makhluk yang sedang ada
	 *         di petak
	 */
	public int totalMakhlukinPetak() {
		return nTotalMakhluk;
	}

	/**
	 * Sebagai fungsi mengembalikan nilai jumlah maksimum makhluk yang dibolehkan
	 * pada petak
	 * 
	 * @return MaxTotalMakhluk sebagai nilai kembalian jumlah makhluk yang
	 *         dibolehkan pada petak
	 */
	public int getMaxTotalMakhluk() {
		return maxTotalMakhluk;
	}

	/**
	 * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak Makhluk
	 * akan diletakkan pada posisi acak
	 * 
	 * @return M sebagai kembalian makhluk apa yang akan dimunculkan
	 */
	public Makhluk spawn() {
		Random rnd = new Random();
		int baris = rnd.nextInt(panjang - 1);
		int kolom = rnd.nextInt(lebar - 1);
		int tipe = rnd.nextInt(5) + 1;
		Makhluk M;

		switch (tipe) {
		case 1:
			M = new MakhlukAntiAir(baris, kolom);
			break;
		case 2:
			M = new MakhlukBurukRupa(baris, kolom);
			break;
		case 3:
			M = new MakhlukMaling(baris, kolom);
			break;
		case 4:
			M = new MakhlukMonster(baris, kolom);
			break;
		case 5:
			M = new MakhlukTerbang(baris, kolom);
			break;
		default:
			M = new MakhlukAntiAir(baris, kolom);
		}

		cells[baris][kolom].addMakhluk(M);
		nTotalMakhluk++;
		return M;
	}

	/**
	 * Fungsi untuk menghidupkan sebuah makhluk dan memunculkan pada petak Makhluk
	 * akan diletakkan pada posisi acak
	 * 
	 * @param i parameter untuk lokasi x dalam petak
	 * @param j parameter untuk lokasi y dalam petak
	 * @param t parameter tipe makhluk yang akan ditampilkan
	 * @return M sebagai kembalian makhluk apa yang akan dimunculkan
	 */
	public Makhluk spawn(int i, int j, int t) {
		int baris = i;
		int kolom = j;
		int tipe = t;
		Makhluk M = null;
		switch (tipe) {
		case 1:
			M = new MakhlukAntiAir(baris, kolom);
			break;
		case 2:
			M = new MakhlukBurukRupa(baris, kolom);
			break;
		case 3:
			M = new MakhlukMaling(baris, kolom);
			break;
		case 4:
			M = new MakhlukMonster(baris, kolom);
			break;
		case 5:
			M = new MakhlukTerbang(baris, kolom);
			break;
		default:
			M = new MakhlukAntiAir(baris, kolom);
		}
		cells[baris][kolom].addMakhluk(M);
		nTotalMakhluk++;
		return M;
	}

	/**
	 * Prosedur mengecek perpindahan suatu makhluk dan memperbarui status lokasi
	 * makhluk pada petak
	 * 
	 * @param i lokasi yang ingin dipastikan (x) pada petak
	 * @param j lokasi yang ingin dipastikan (y) pada petak
	 */
	public void moveMakhluk(int i, int j) {
		boolean exit = false;
		if (!cells[i][j].isEmpty()) {
			while (cells[i][j].isOver()) {
				Makhluk N = cells[i][j].survFight();
				deleteMakhluk(N);
			}
			Makhluk M;
			do {
				M = cells[i][j].checkMoveMakhluk(i, j);
				if (M != null) {
					int x = M.getX();
					int y = M.getY();
					int umur = M.getAgeNow();
					int umurmax = M.getAge();

					if ((x < panjang) && (y < lebar) && (x >= 0) && (y >= 0) && (umur <= umurmax)) {
						if (cells[x][y].isFull()) {
							cells[x][y].addMakhluk(M);
							Makhluk N = cells[x][y].survFight();
							deleteMakhluk(N);
						} else
							cells[x][y].addMakhluk(M);
					} else {
						deleteMakhluk(M);
						M = cells[i][j].checkMoveMakhluk(i, j);
						if (M == null)
							exit = true;
					}
				}
			} while ((M != null) && (!exit));
		}
	}

	/**
	 * Prosedur mengperbarui tampilan
	 * 
	 * @param V sebagai pengontrol tampilan
	 */
	public void updateWorld(View V) {
		for (int i = 0; i < panjang; i++) {
			for (int j = 0; j < lebar; j++) {
				moveMakhluk(i, j);
			}
		}

		for (int i = 0; i < panjang; i++) {
			for (int j = 0; j < lebar; j++) {
				for (int k = 0; k < cells[i][j].getNMakhluk(); ++k) {
					Makhluk R = cells[i][j].getMakhlukin(k);
					V.showBentuk(R.getType());
				}
				int n = cells[i][j].getNMakhluk();
				int max = cells[i][j].getMaxMakhluk();
				for (int k = n; k < max; k++)
					System.out.print(" ");
				System.out.print("|");
			}
			System.out.println();
		}
	}

	/**
	 * Prosedur menghapus makhluk pada suatu petak
	 * 
	 * @param M untuk identifikasi makhluk yang ingin dihapus
	 */
	public void deleteMakhluk(Makhluk M) {
		for (int i = 0; i < this.maxTotalMakhluk; i++) {
			if (M == creature[i]) {
				creature[i] = null;
				this.nTotalMakhluk--;
			}
		}
		M = null;
	}

	/**
	 * Prosedur untuk secara otomatis membangkitkan makhluk baru
	 */
	public void autoSpawn() {
		int i = 0;
		while ((creature[i] != null) && (i < maxTotalMakhluk))
			i++;

		if (creature[i] == null)
			creature[i] = spawn();
	}

	/**
	 * Memulai sebuah program
	 * 
	 * @throws IOException Exception when failed access an file to screenshot
	 * @throws InterruptedException Exception when program pause do some force interuption
	 */
	public void start() throws IOException, InterruptedException {
		View viewer = new View();
		int delT = 0;
		Random rnd = new Random();
		int t = rnd.nextInt(maxTotalMakhluk / 4) + (maxTotalMakhluk / 6);
		for (int i = 0; i < t; i++) {
			this.creature[i] = this.spawn();
			try {
				Thread.sleep(250);
			} catch (InterruptedException ex) {
				Thread.currentThread().interrupt();
			}
			new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
			float load = 100 * i / (float) t;
			System.out.println("Now loading " + load + " %");
		}
		new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		System.out.println("Now loading " + 100 + " %");
		boolean stop = false;
		while ((totalMakhlukinPetak()) > 0 && !stop) { // pause
			pause();
			// Exit
			exit();
			// screenshot
			screenshot(viewer);
			// spawn
			spawn(viewer);
			// step by step execution
			while (step) {
				int z = 0;
				while (z < 10) {
					if (delT == 10000) {
						delT = 0;
					}
					delT++;
					step(delT);
					++z;
				}
				new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
				updateWorld(viewer);
				System.out.println();
				System.out.println("Step-by step execution 0.1 second");
				step = false;
				pause = true;
				pause();
			}
			new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
			updateWorld(viewer);
			System.out.println();
			if (delT == 10000) {
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
		new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		System.out.println();
		System.out.println("========================");
		System.out.println("Semua makhluk telah mati");
		System.out.println("      GAME OVER");
		System.out.println("========================");
		System.out.println();
		System.out.println("Press any key to exit");
	}

	/**
	 * Memberhentikan sementara program
	 * 
	 * @throws InterruptedException Exception when program pause do some force interuption
	 */
	public void pause() throws InterruptedException {
		if (pause) {
			System.out.println("Paused..... Press R in KeyListener to resume");
		}
		while (pause) {
			Thread.sleep(1);
		}
	}

	/**
	 * Keluar dari program
	 * 
	 * @throws InterruptedException Exception when program pause do some force interuption
	 */
	public void exit() throws InterruptedException {
		if (exit) {
			System.out.println();
			System.out.println("===================================");
			System.out.println("Anda Telah Menekan ESC Untuk Keluar");
			System.out.println("            GAME OVER");
			System.out.println("===================================");
			System.out.println();
			pause = true;
			pause();
			System.exit(0);
		}
	}

	/**
	 * Menyimpan tampilan pada saat tertentu
	 * 
	 * @param V sebagai viewer
	 * @throws InterruptedException Exception when program pause do some force interuption
	 * @throws FileNotFoundException Exception when not found an file
	 */
	public void screenshot(View V) throws InterruptedException, FileNotFoundException {
		if (screenshot) {
			System.out.println("Screenshot telah disimpan!");
			printToFile(V);
			System.out.println("Press any key to continue");
			pause = true;
			pause();
			screenshot = false;
		}
	}

	/**
	 * Menulis isi matriks ke dalam file
	 * 
	 * @param V sebagai viewer
	 * @throws FileNotFoundException Exception when not found a file
	 */
	public void printToFile(View V) throws FileNotFoundException {
		PrintWriter f = new PrintWriter("screenshot.txt");
		for (int i = 0; i < panjang; i++) {
			for (int j = 0; j < lebar; j++) {
				for (int k = 0; k < cells[i][j].getNMakhluk(); ++k) {
					Makhluk R = cells[i][j].getMakhlukin(k);
					f.print(V.getBentuk(R.getType()));
				}
				int n = cells[i][j].getNMakhluk();
				int max = cells[i][j].getMaxMakhluk();
				for (int k = n; k < max; k++)
					f.print(" ");
				f.print("|");
			}
			f.println();
		}
		f.close();
	}

	/**
	 * Memunculkan berbagai makhluk
	 * 
	 * @param viewer sebagai viewer
	 * @throws IOException Exception when not found a file
	 * @throws InterruptedException Exception when program pause do some force interuption
	 */
	public void spawn(View viewer) throws IOException, InterruptedException {
		while (spawn) {

			if (nTotalMakhluk < maxTotalMakhluk) {
				new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
				autoSpawn();
				updateWorld(viewer);
				System.out.println(" Telah Muncul Satu Makhluk Baru!");
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
	 * Menggerakan step by step
	 * 
	 * @param delT sebagai masukan deltaT saat itu
	 */
	public void step(int delT) {
		for (int i = 0; i < maxTotalMakhluk; i++) {
			if (creature[i] != null) {
				creature[i].move();
			}
		}
		if (nTotalMakhluk < maxTotalMakhluk) {
			Random rand = new Random();
			if (delT % 2 == 0) {
				int x1 = rand.nextInt(20);
				int x2 = rand.nextInt(5);
				if (x1 < x2) {
					autoSpawn();
				}
			} else {
				int x1 = rand.nextInt(5);
				int x2 = rand.nextInt(10) + 2;
				if (x1 >= x2) {
					autoSpawn();
				}
			}
		}
	}
}
