package makhlukinaction.model;

import java.util.Random;

/**
 * @author Jeremia Jason Lasiman - 13514021
 */
public class MakhlukBurukRupa extends Makhluk {
	/**
	 * constructor without parameter of MakhlukBurukRupa
	 */
	public MakhlukBurukRupa() {
		age = 80; // lambat mati
		powerLevel = 80; // normal
		deltaT = 7; // cukup lambat
		type = 2;
		ageNow = 0;
	}

	/**
	 * @param a this is the x position of makhluk
	 * @param b this is the y position of makhluk constructor without parameter of
	 *          MakhlukBurukRupa
	 */
	public MakhlukBurukRupa(int a, int b) {
		age = 80; // lambat mati
		powerLevel = 80; // normal
		deltaT = 7; // cukup lambat
		type = 2;
		ageNow = 0;
		x = a;
		y = b;
	}

	/**
	 * this procedure is to change the makhluk position (x,y) each deltaT cycle.
	 */
	@Override
	public void move() {
		if (deltaT == 0) {
			Random rand = new Random();
			int r1 = rand.nextInt(3) - 1;
			y = y + r1;
			ageNow++;
			deltaT = 7;
		} else
			deltaT--;
	}
}