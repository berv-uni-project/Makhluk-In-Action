/**
 * @author Jeremia Jason Lasiman - 13514021
 * */

public abstract class Makhluk {
        /** type : each makhluk has different type.
         * to differentiate their appearance.*/
        protected int type;
	/** age : maximum age / lifespan of makhluk.*/
        protected int age;
	/** agenow : current age of makhluk (counted by cycle).*/
        protected int agenow;
	/** powerlevel : strength of makhluk to survive battles.*/
        protected int powerlevel;
	/** time (per cycle) needed for makhluk to move.*/
	protected int deltaT;
	/** x : x position of makhluk.*/
	protected int x;
	/** y : y position of makhluk.*/
	protected int y;
        /** this procedure is to change makhluk position (x,y).
         * each deltaT cycle.*/
        public abstract void move();

        /** this function is to get makhluk's strength.
         * @return powerlevel */
        public final int getpowerlevel() {
            return powerlevel; }

        /** this function is to get maximum age of makhluk.
         * @return age */
        public final int getage() {
            return age; }

        /** this function is to get current age of makhluk.
         * @return agenow */
        public final int getagenow() {
            return agenow; }

        /**this function is to get time needed for makhluk to move.
         * @return deltaT */
        public final double getdeltaT() {
            return deltaT; }

        /** this function is to return makhluk's type for appearance.
         * @return type*/
        public final int gettype() {
            return type; }

        /** this function is to get X position of makhluk.
         * @return x */
        public final int getX() {
            return x; }

        /** this function is to get Y position of makhluk.
         * @return y */
        public final int getY() {
            return y; }
}

