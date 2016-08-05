package makhluk;

import java.awt.Graphics;
/**
 * @author Jeremia Jason Lasiman - 13514021
 * */
public abstract class Makhluk {
    /** Type to differentiate their appearance.*/
    private int type;
    /** Strength of makhluk to survive battles.*/
    private int powerlevel;
    /** X position of makhluk.*/
    private int x;
    /** Y position of makhluk.*/
    private int y;
    /** Check if Makhluk is alive or dead.*/
    private boolean alive;

    /** This function is to get makhluk's strength.
      * @return powerlevel */
    public int getpowerlevel() {
        return powerlevel; }
    /** This function is to return makhluk's type for appearance.
      * @return type*/
    public final int gettype() {
        return type; }
    /** This function is to get X position of makhluk.
      * @return x */
    public final int getX() {
        return x; }
    /** This function is to get Y position of makhluk.
      * @return y */
    public final int getY() {
        return y; }
    /** this procedure is to get alive of makhluk.
      * @return alive */
    public final boolean getAlive() {
        return alive;
    }
    /** this procedure is to set X position of makhluk.
      * @param x1 X position of makhluk */
    public final void setX(final int x1) {
        x = x1;
    }
    /** this procedure is to set Y position of makhluk.
      * @param y1 Y position of makhluk */
    public final void setY(final int y1) {
        y = y1;
    }
    /** This procedure is to set type of makhluk.
      * @param type1 The type of makhluk */
    public final void setType(final int type1) {
        type = type1;
    }
    /** This procedure is to set power level of makhluk.
      * @param pwl The power level of makhluk */
    public final void setPowerLevel(final int pwl) {
        powerlevel = pwl;
    }
    /** this procedure is to set state of makhluk.
      * @param isAlive The state of makhluk */
    public final void setAlive(final boolean isAlive) {
        alive = isAlive;
    }
    /** this procedure is to set Y alive of makhluk.*/
    public final void setDead() {
        alive = false;
    }
    /** this procedure make Makhluk Fight.
      * @param a Makhluk that will fight */
    public final void fight(final Makhluk a) {
        if (powerlevel > a.getpowerlevel()) {
            a.setDead();
        } else {
           assert (powerlevel <= a.getpowerlevel());
           this.alive = false;
       }
    }
    /** this procedure is to draw makhluk.
      * @param g Graphics */
    public abstract void draw(Graphics g);
}
