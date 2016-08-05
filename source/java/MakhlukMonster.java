import java.util.Random;

/**
 * @author Jeremia Jason Lasiman - 13514021
 */
public class MakhlukMonster extends Makhluk
{
	/**
	 * constructor without parameter of MakhlukMonster
	 */
	public MakhlukMonster()
	{
		age = 60; // lambat mati
		powerlevel = 100; //paling kuat
		deltaT = 10; //lambat
		type = 4;
		agenow = 0;
	}

	/**
	 * @param a this is the x position of makhluk
	 * @param b this is the y position of makhluk
	 * constructor without parameter of MakhlukMonster
	 */
	public MakhlukMonster(int a,int b)
	{
		age = 60; // lambat mati
		powerlevel = 100; //paling kuat
		deltaT = 10; //lambat
		type = 4;
		agenow = 0;
		x = a;
		y = b;
	}

	/**
	 * this procedure is to change the makhluk position (x,y) each deltaT cycle.
	 */
        @Override
	public void move()
	{
		if (deltaT == 0)
		{
			Random rand = new Random();
			int r1, r2;
			r1 = rand.nextInt(3) - 1; //cek lagi benernya gimana
			x = x + r1;
			agenow++;
			deltaT = 10;
		}
		else
			deltaT--;
	}

};