/**
 * @author Jeremia Jason Lasiman 
 * */

abstract public class Makhluk {
	/**
	 * type : each makhluk has different type to differentiate their appearance
	 */
	protected int type;
	/**
	 * age : maximum age / lifespan of makhluk.
	 */
	protected int age;
	/**
	 *  agenow : current age of makhluk (counted by cycle)
	 */
	protected int agenow;
	/**
	 * powerlevel : strength of makhluk to survive battles
	 */
	protected int powerlevel;
	/**
	 * time (per cycle) needed for makhluk to move
	 */
	protected int deltaT;
	/**
	 * x : x position of makhluk
	 */
	protected int x;
	/**
	 * y : y position of makhluk
	 */
	protected int y;
	
	/**
	 * this procedure is to change the makhluk position (x,y) each deltaT cycle.
	 */
	public abstract void move();

	/**
	 * this function is to get makhluk's strength
	 * @return powerlevel,
	 * */
	public int getpowerlevel()
	{ return powerlevel; }

	/**
	 * this function is to get maximum age of makhluk
	 * @return age,
	 * */
	public int getage()
	{ return age; }
	
	/**
	 * this function is to get current age of makhluk
	 * @return agenow,
	 * */
	public int getagenow()
	{ return agenow; }

	/**
	 * this function is to get time needed for makhluk to move
	 * @return deltaT,
	 * */
	public double getdeltaT()
	{ return deltaT; }

	/**
	 * this function is to return makhluk's type for appearance
	 * @return type,
	 * */
	public int gettype()
	{ return type; }

	/**
	 * this function is to get X position of makhluk
	 * @return x,
	 * */
	public int getX()
	{ return x; }

	/**
	 * this function is to get Y position of makhluk
	 * @return y,
	 * */
	public int getY()
	{ return y; }

}

