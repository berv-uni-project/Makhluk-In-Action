/**
 * @author JJ
 */

public final class MakhlukPlayer extends Makhluk {
    /**const direction for case 1.*/
    private static final int DIR1 = 1;
    /**const direction for case 2.*/
    private static final int DIR2 = 2;
    /**const direction for case 3.*/
    private static final int DIR3 = 3;
    /**const direction for case 4.*/
    private static final int DIR4 = 4;


    /** known static x location of player.*/
    private static int xPlayer;
    /** known static y location of player.*/
    private static int yPlayer;
    /** default powerlevel.*/
    private static final int DEFAULT_POWERLEVEL = 61;
    /** powerlevel required for evolving.*/
    private static final int EVOLVE_REQ = 10;
    /** evolution level.*/
    private int evolution;

     /** private constructor of MakhlukPlayer, setting all value.
     * @param a
     * @param b
     */
    private MakhlukPlayer(final int a, final int b) {
        powerlevel = DEFAULT_POWERLEVEL;
        type = 0;
        xPlayer = a;
        yPlayer = b;
        x = xPlayer;
        y = yPlayer;
        evolution = 0;
    }


    /**Creating player.*/
    public static void spawnPlayer() {
        MakhlukPlayer player = new MakhlukPlayer(0, 0);
    }

    @Override
    public void move() {
        x = xPlayer;
        y = yPlayer;
    }

     /** function to move player with key press from keyboard.
     * @param direction */
    public void move(final int direction) {
        switch (direction) {
            case DIR1 :
                xPlayer += 1;
                break;
            case DIR2 :
                yPlayer += 1;
                break;
            case DIR3 :
                xPlayer -= 1;
                break;
            case DIR4 :
                yPlayer -= 1;
                break;
            default :
        }
    }

    /** static method to make make player go up. */
    public static void playerUp() {
        xPlayer++;
    }
    /** static method to make make player go down. */
    public static void playerDown() {
        xPlayer--;
    }
    /** static method to make make player go right. */
    public static void playerRight() {
        yPlayer++;
    }
    /** static method to make make player go left. */
    public static void playerLeft() {
        yPlayer--;
    }

    /**.
     * procedure to notify that player has eaten something.
     * powerlevel will be increased by 1 every Makhluk Player eat
     * also trigger for evolving
     */
    public void playerEat() {
        powerlevel = powerlevel + 1;
        int realpower = evolution * EVOLVE_REQ;
        int powernow = powerlevel - DEFAULT_POWERLEVEL - realpower;
        if (powernow > EVOLVE_REQ) {
            evolution++;
        }
    }

}
