package Test;

import java.util.Random;

/**
 *  @author Jeremia Jason Lasiman - 13514021
 */
public class MakhlukBurukRupa extends Makhluk {
    /** default age. */
    private static final int DEFAULT_AGE = 80;
    /** default powerlevel. */
    private static final int DEFAULT_POWERLEVEL = 70;
    /** default deltaT. */
    private static final int DEFAULT_DELTAT = 7;
    /** default type. */
    private static final int DEFAULT_TYPE = 2;
    /** default agenow. */
    private static final int DEFAULT_AGENOW = 0;
    /** to make random 0-2 and minus 1 at the end. */
    private static final int RAND_MOVE = 2;

    /** constructor without parameter of MakhlukBurukRupa. */
    public MakhlukBurukRupa() {
        age = DEFAULT_AGE;
        powerlevel = DEFAULT_POWERLEVEL;
        deltaT = DEFAULT_DELTAT;
        type = DEFAULT_TYPE;
        agenow = DEFAULT_AGENOW;
        alive = true;
    }

    /**
     * @param a this is the x position of makhluk
     * @param b this is the y position of makhluk
     * constructor without parameter of MakhlukBurukRupa
     */
    public MakhlukBurukRupa(final int a, final int b) {
        age = DEFAULT_AGE;
        powerlevel = DEFAULT_POWERLEVEL;
        deltaT = DEFAULT_DELTAT;
        type = DEFAULT_TYPE;
        agenow = DEFAULT_AGENOW;
        x = a;
        y = b;
        alive = true;
    }

    /** procedure to make Makhluk move .*/
    @Override
    public final void move() {
        if (deltaT == 0) {
            Random rand = new Random();
            int r1;
            r1 = rand.nextInt(RAND_MOVE) - 1;
            y = y + r1;
            agenow++;
            deltaT = DEFAULT_DELTAT;
        } else {
            deltaT--;
        }
    }
};
