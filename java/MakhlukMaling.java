import java.util.Random;

/**
 *
 * @author Jeremia
 */
public class MakhlukMaling extends Makhluk
{
	/**
	 * constructor without parameter of MakhlukMaling
	 */
	public MakhlukMaling()
	{
		age = 40; //normal
		powerlevel = 75; // cukup lemah
		deltaT = 5; // cukup cepat 
		type = 3;
		agenow = 0;
	}

	/**
	 * @param a this is the x position of makhluk
	 * @param b this is the y position of makhluk
	 * constructor without parameter of MakhlukMaling
	 */
	public MakhlukMaling(int a,int b)
	{
		age = 40; //normal
		powerlevel = 75; // cukup lemah
		deltaT = 5; // cukup cepat 
		type = 3;
		agenow = 0;
		x = a;
		y = b;
	}

	/**
	 * this procedure is to change the makhluk position (x,y) each deltaT cycle.
	 */
	public void move()
	{
		if (deltaT == 0)
		{
			Random rand = new Random();
			int r1, r2;
			r1 = rand.nextInt(3) - 1;
			r2 = rand.nextInt(3) - 1;
			x = x + r1;
			y = y + r2;
			agenow++;
			deltaT = 5;
		}
		else
			deltaT--;
	}

};