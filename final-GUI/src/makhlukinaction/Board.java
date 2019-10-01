package makhlukinaction;

import makhluk.Makhluk;
import makhluk.MakhlukPlayer;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;


/**
 *
 * @author Joshua
 */
public final class Board extends JPanel implements ActionListener, KeyListener {
    /**default refresh time.*/
    private static final int REFRESH_TIME = 5;
    /**default red value.*/
    private static final int RED1 = 255;
    /**default green value.*/
    private static final int GREEN1 = 0;
    /**default blue value.*/
    private static final int BLUE1 = 255;
    /**deafult small title font size. */
    private static final int TITLE_SIZE_S = 15;
    /**deafult small title font size. */
    private static final int TITLE_SIZE_M = 25;
    /**deafult title font size. */
    private static final int TITLE_SIZE = 50;
    /**GAME OVER / WIN title X position. */
    private static final int TXPOS = 180;
    /**GAME OVER / WIN title Y position. */
    private static final int TYPOS = 290;
    /**Makhluk in action title X position. */
    private static final int MIAX = 10;
    /**Makhluk in action title Y position. */
    private static final int MIAY = 15;
    /**Makhluk in action title 2 X position. */
    private static final int MIAX2 = 275;
    /**Makhluk in action title 2 Y position. */
    private static final int MIAY2 = 75;
    /**Type of Makhluk Monster. */
    private static final int TYPE4 = 4;
    /**const numbers you can see the trap. */
    private static final int MA1 = 15;
    /**numbers you can see the trap. */
    private static int cheat = MA1;
    /**the score of game. */
    private int score = 0;
    /**check space. */
    private boolean space = false;
    /**array list from command control. */
    private ArrayList<Makhluk> al;

    /**constructor of board.
     * @param al1 list */
    public Board(final ArrayList<Makhluk> al1) {
        int r = 0;
        int g = 0;
        int b = 0;
        al = new ArrayList<Makhluk>();
        final Timer timer = new Timer(REFRESH_TIME, this);
        Color backgroundColor = new Color(r, g, b);
        setBackground(backgroundColor);
        al = al1;
        timer.start();
        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
        score = 0;
    }

    /**draw board if game over.
     * @param g Graphics input */
    public void drawGameOver(final Graphics g) {
        Color b = new Color(RED1, GREEN1, BLUE1);
        g.setColor(b);
        g.setFont(new Font("Calibri", Font.BOLD, TITLE_SIZE));
        g.drawString("Game Over !", TXPOS, TYPOS);
        g.drawString("Your Score : " + score, TXPOS, TYPOS + TITLE_SIZE);
    }

    /**draw board if player win the game.
     * @param g Graphics input */
    public void drawWin(final Graphics g) {
        Color b = new Color(RED1, GREEN1, BLUE1);
        g.setColor(b);
        g.setFont(new Font("Calibri", Font.BOLD, TITLE_SIZE));
        g.drawString("You Win The Game!", TXPOS, TYPOS);
        g.drawString("Your Score : " + score, TXPOS, TYPOS + TITLE_SIZE);
    }

    /**draw the trap.
     * @param g Graphics input */
    public void drawTrap(final Graphics g) {
        for (int i = 0; i < al.size(); i++) {
            if (al.get(i).getAlive()) {
                al.get(i).draw(g);
                }
            }
    }

    /**draw board's border.
     * @param g Graphics input */
    public void drawborder(final Graphics g) {
        final int left2 = 10;
        final int right2 = 100;
        final int top2 = 660;
        final int bottom2 = 550;
        final int left1 = 12;
        final int right1 = 102;
        final int top1 = 655;
        final int bottom1 = 545;
        Graphics2D g2 = (Graphics2D) g;
        Color b = new Color(RED1, GREEN1, BLUE1);
        final int magic2 = 525;
        final int magic3 = 10;
        final int magic4 = 25;
        final int magic5 = 40;
        final int magic6 = 55;
        final int magic7 = 70;
        final int magic8 = 85;
        g.setColor(b);
        g.setFont(new Font("Calibri", Font.BOLD, TITLE_SIZE_S));
        g.drawString("Your Score : " + score, MIAX, MIAY);
        if (cheat >= 0) {
            g.drawString("Show Trap (SPACE) : " + cheat, MIAX, MIAY + 15);
        } else {
            assert (cheat < 0);
            g.drawString("Show Trap (SPACE) : 0" , MIAX, MIAY + 15);
        }
        g.drawString("Power Level Player : "
                + MakhlukPlayer.getPlayer().getpowerlevel(), magic2, magic3);
        g.drawString("Power Level * : 50", magic2, magic4);
        g.drawString("Power Level % : 55", magic2, magic5);
        g.drawString("Power Level $ : 60", magic2, magic6);
        g.drawString("Power Level ~ : 65", magic2, magic7);
        g.drawString("Power Level @ : 150", magic2, magic8);
        g.setFont(new Font("Calibri", Font.BOLD, TITLE_SIZE_M));
        g.drawString("THE EATER ", MIAX2, MIAY2);
        g.setFont(new Font("Calibri", Font.BOLD, TITLE_SIZE_S));
        Color c = new Color(RED1, GREEN1, BLUE1);
        g.setColor(c);
        g2.fill(new Rectangle2D.Double(left2, right2, top2, bottom2));
        Color d = new Color(0, 0, 0);
        g.setColor(d);
        g2.fill(new Rectangle2D.Double(left1, right1, top1, bottom1));
    }

    @Override
    public void paintComponent(final Graphics g) {
        super.paintComponent(g);
        drawborder(g);
        if (MakhlukPlayer.getPlayer().getAlive() && !MakhlukPlayer.
                getMPlayer().getWin()) {
            for (int i = 0; i < al.size(); i++) {
                if (al.get(i).getAlive() && al.get(i).gettype() != TYPE4) {
                    al.get(i).draw(g);
                }
            }
            if (space && cheat > 0) {
                drawTrap(g);
            }
            if (MakhlukPlayer.getPlayer().getAlive()) {
                MakhlukPlayer.getPlayer().draw(g);
            }
        } else if (!MakhlukPlayer.getPlayer().getAlive()) {
            drawGameOver(g);
        } else {
            assert (MakhlukPlayer.getMPlayer().getWin());
            drawWin(g);
        }
    }
    /**to update the score.
    * @param s input score point */
    public void updateScore(final int s) {
        score = s;
    }

    @Override
    public void actionPerformed(final ActionEvent e) {
        repaint();
    }

    @Override
    public void keyPressed(final KeyEvent e) {
        int key = e.getKeyCode();
        MakhlukPlayer m = MakhlukPlayer.getMPlayer();
        if (key == KeyEvent.VK_UP && !space) {
            up = true;
            MakhlukPlayer.playerUp();
        }
        if (key == KeyEvent.VK_DOWN && !space) {
            down = true;
            MakhlukPlayer.playerDown();
        }
        if (key == KeyEvent.VK_RIGHT && !space) {
            right = true;
            MakhlukPlayer.playerRight();
        }
        if (key == KeyEvent.VK_LEFT && !space) {
            left = true;
            MakhlukPlayer.playerLeft();
        }
        if (key == KeyEvent.VK_SPACE) {
            space = true;
        }
        m.move();
    }

    @Override
    public void keyTyped(final KeyEvent e) {
        // System.out.println(e.getKeyCode());
    }

    @Override
    public void keyReleased(final KeyEvent e) {
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_SPACE) {
            space = false;
            --cheat;
        }
    }
}
