package makhlukinaction;

import java.io.IOException;
import java.util.Scanner;

/**
 * @author M. Az-zahid Adhitya Silparensi-13514095
 */
public class Main {
	/**
	 * Main program
	 * 
	 * @param args sebagai masukan argumen yang diinginkan
	 * @throws IOException Exception when not found a file
	 * @throws InterruptedException Exception when program pause do some force interuption
	 */
	public static void main(String[] args) throws IOException, InterruptedException {
		int blockSize = 20;
		int maxMakhluk = 50;
		new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		boolean stop = false;
		while (!stop) {
			System.out.println("Apakah anda ingin membuat ukuran field sendiri? (Y/N)");
			char currentChar;
			Scanner sn = new Scanner(System.in);
			currentChar = sn.next().charAt(0);
			if (currentChar == 'Y') {
				System.out.print("Masukkan ukuran field : ");
				blockSize = sn.nextInt();
				System.out.println();
				System.out.print("Masukkan maksimal makhluk : ");
				maxMakhluk = sn.nextInt();
				System.out.println();
				stop = true;
			} else if (currentChar == 'N') {
				blockSize = 20;
				maxMakhluk = 50;
				stop = true;
			} else {
				System.out.println("Masukan Salah Tolong Ulangi!");
			}
		}
		// Menciptakan objek Control
		ControlCommand controller = new ControlCommand(blockSize, blockSize, maxMakhluk);
		new KeyListenerForMe("Key Listener POKEMAN", controller);
		controller.start();
	}
}
