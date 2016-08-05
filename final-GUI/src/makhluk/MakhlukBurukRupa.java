package makhluk;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

/**
 * @author Jeremia Jason Lasiman - 13514021
 * */
public class MakhlukBurukRupa extends Makhluk {

    /** default power level. */
    private static final int DEFAULT_POWERLEVEL = 55;
    /** default type. */
    private static final int DEFAULT_TYPE = 2;

    /** constructor without parameter of MakhlukAntiAir.*/
    public MakhlukBurukRupa() {
        final int randomize1 = 40;
        final int randomize2 = 140;
        super.setPowerLevel(DEFAULT_POWERLEVEL);
        super.setType(DEFAULT_TYPE);
        super.setAlive(true);
        int random1, random2;
        final int m = 560;
        final int m2 = 510;
        random1 = (int) (Math.random() * m + randomize1);
        random2 = (int) (Math.random() * m2 + randomize2);
        super.setX(random1);
        super.setY(random2);
    }

    /** constructor with position parameter of MakhlukAntiAir.
     * @param a this is the x position of makhluk
     * @param b this is the y position of makhluk
     */
    public MakhlukBurukRupa(final int a, final int b) {
        super.setPowerLevel(DEFAULT_POWERLEVEL);
        super.setType(DEFAULT_TYPE);
        super.setAlive(true);
        super.setX(a);
        super.setY(b);
    }
    /** draw the shape of Makhluk.
     * @param g Graphics
     */
    @Override
    public final void draw(final Graphics g) {
        final int red = 255;
        final int green = 0;
        final int blue = 0;
        final int fontsize = 18;
        Color mycolor = new Color(red, green, blue);
        g.setColor(mycolor);
        g.setFont(new Font("Courier New", Font.BOLD, fontsize));
        g.drawString("%", super.getX(), super.getY());
    }
};
