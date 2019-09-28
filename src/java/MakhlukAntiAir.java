import java.util.Random;

/**
 *  @author Jeremia Jason Lasiman - 13514021
 */
public class MakhlukAntiAir extends Makhluk
{
	/**
	 * constructor without parameter of MakhlukAntiAir
	 */
	public MakhlukAntiAir()
	{
		age = 90; //lambat mati
		powerlevel = 60; //cukup lemah
		deltaT = 8;  //cukup lambat
		type = 1;
		agenow = 0;
	}

	/**
	 * constructor with position parameter of MakhlukAntiAir
         * @param a this is the x position of makhluk
	 * @param b this is the y position of makhluk
	 */
	public MakhlukAntiAir(int a,int b)
	{
		age = 90; //lambat mati
		powerlevel = 60; //cukup lemah
		deltaT = 8;  //cukup lambat
		type = 1;
		agenow = 0;
		x = a;
		y = b;
	}

	/**
	 * this procedure is to change the makhluk position (x,y) each deltaT cycle.
	 */
        @Override
	public void move() //jalannya terserah, tapi kekuatannya mantap
	{
		if (deltaT == 0)
		{
			Random rand = new Random();
			int r1 = 0, r2 = 0;
			while (r1 == 0 || r2 == 0)
			{
				r1 = rand.nextInt(3) - 1; //nextInt(n) --> random dengan maksimal n,
				r2 = rand.nextInt(3) - 1; // -1 --> nilai minimal
			}
			x = x + r1;
			y = y + r2;
			agenow++;
			deltaT = 8;
		}
		else
			deltaT--;
	}

};