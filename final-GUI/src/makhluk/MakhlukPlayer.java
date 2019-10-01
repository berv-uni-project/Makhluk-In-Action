package makhluk;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

/**
 * @author Jeremia Jason Lasiman - 13514021
 * */
public final class MakhlukPlayer extends Makhluk {

    /** known static x location of player.*/
    private static int xPlayer;
    /** known static y location of player.*/
    private static int yPlayer;
    /** player exclusive power level. */
    private static int pPow;
    /** to make sure the player have won the game.*/
    private static boolean win;
    /** score of player.*/
    private static int score;
    /** default power level.*/
    private static final int DEFAULT_POWERLEVEL = 51;
    /** default type of player. */
    private static final int DEFAULT_TYPE = 0;
    /**size of pixels in makhluk. */
    private static final int PIXEL_SPACE = 10;
    /**evo requirement of makhluk. */
    private static final int EVO_REQ = 25;
    /** static player of this game. */
    private static MakhlukPlayer player = new MakhlukPlayer();
     /** private constructor of MakhlukPlayer, setting all value. */
    private static int evo;
    /** Private constructor. */
    private MakhlukPlayer() {
        final int initialx = 20;
        final int initialy = 120;
        xPlayer = initialx;
        yPlayer = initialy;
        super.setPowerLevel(DEFAULT_POWERLEVEL);
        super.setType(DEFAULT_TYPE);
        super.setX(xPlayer);
        super.setY(yPlayer);
        super.setAlive(true);
        win = false;
        pPow = DEFAULT_POWERLEVEL;
        score = 0;
        evo = 0;
    }
    /**return score of player.
     * @return score */
    public static int score() {
        return score;
    }

    /**plus score per player eat. */
    public static void playerEat() {
        pPow = pPow + 1;
        final int plus = 5;
        score = score + plus;
        evo = score / EVO_REQ;
    }
    /** to get win status.
     * @return win */
    public boolean getWin() {
        return win;
    }
    /** to set win.
     * @param win2 input boolean */
    public static void setWin(final boolean win2) {
        win = win2;
    }
    /** to spawn player. */
    /** a procedure to make player move. */
    public void move() {
        super.setPowerLevel(pPow);
        super.setX(xPlayer);
        super.setY(yPlayer);
    }

    /** static method to make make player go up. */
    public static void playerUp() {
        yPlayer = yPlayer - PIXEL_SPACE;
    }
    /** static method to make make player go down. */
    public static void playerDown() {
        yPlayer = yPlayer + PIXEL_SPACE;
    }
    /** static method to make make player go right. */
    public static void playerRight() {
        xPlayer = xPlayer + PIXEL_SPACE;
    }
    /** static method to make make player go left. */
    public static void playerLeft() {
        xPlayer = xPlayer - PIXEL_SPACE;
    }
    /**return makhluk player of this game.
     * @return player*/
    public static Makhluk getPlayer() {
        if (player == null) {
            player = new MakhlukPlayer();
        }
        return player;
    }

    @Override
    public int getpowerlevel() {
        return pPow;
    }
   /**return makhluk player of this game.
     * @return player*/
    public static MakhlukPlayer getMPlayer() {
        if (player == null) {
            player = new MakhlukPlayer();
        }
        return player;
    }
     /** draw the shape of Makhluk.
     * @param g Graphics
     */
    @Override
    public void draw(final Graphics g) {
        final int red = 0;
        final int green = 255;
        final int blue = 0;
        final int fontsize = 18;
        Color mycolor = new Color(red, green, blue);
        g.setColor(mycolor);
        g.setFont(new Font("Courier New", Font.BOLD, fontsize));
        char p = 'A';
        for (int i = 0; i < evo; i++) {
            p++;
        }
        g.drawString(String.valueOf(p), super.getX(), super.getY());
    }
}
