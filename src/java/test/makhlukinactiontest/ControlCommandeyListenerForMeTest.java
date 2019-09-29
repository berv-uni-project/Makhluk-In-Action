package makhlukinactiontest;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.Random;
import java.io.IOException;
import java.util.Scanner;
import makhlukinaction.*;
/**
 *
 * @author Joshua
 */

// Oleh karena Control Command banyak System.out.println dan KeyListener hanya
// dapat di main
// tester atau driver menggunakan Main yang sama dengan Main.java untuk mengetes
// seluruhnya jalan atau tidak
public class ControlCommandeyListenerForMeTest {
	public static void main(String[] args) throws IOException, InterruptedException {
		int u = 20;
		int max = 50;
		new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
		boolean stop = false;
		while (!stop) {
			System.out.println("Apakah anda ingin membuat ukuran field sendiri? (Y/N)");
			char C;
			Scanner sn = new Scanner(System.in);
			C = sn.next().charAt(0);
			if (C == 'Y') {
				System.out.print("Masukkan ukuran field : ");
				u = sn.nextInt();
				System.out.println();
				System.out.print("Masukkan maksimal makhluk : ");
				max = sn.nextInt();
				System.out.println();
				stop = true;
			} else if (C == 'N') {
				u = 20;
				max = 50;
				stop = true;
			} else {
				System.out.println("Masukan Salah Tolong Ulangi!");
			}
		}
		// Menciptakan objek Control
		ControlCommand P = new ControlCommand(u, u, max);
		new KeyListenerForMe("Key Listener POKEMAN", P);
		P.start();
	}
}
