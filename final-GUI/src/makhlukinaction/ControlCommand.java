package makhlukinaction;

import makhluk.Makhluk;
import makhluk.MakhlukPlayer;
import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @author Joshua
 */
public class ControlCommand extends Thread {
    /**array list of makhluk. */
    private ArrayList<Makhluk> al;
    /**makhluk player. */
    private Makhluk player;
    /**board. */
    private Board board;
    /**default number of enemy makhluk spawned 18. */
    private final static int DEFAULT_MAKHLUK_SPAWNED = 18;
    /**default number of enemy makhluk spawned 35. */
    private final static int DEFAULT_MAKHLUK_SPAWNED2 = 35;
    /**Control command (singleton). */
    private static final ControlCommand cc = new ControlCommand();
    /** CommandControl constructor. */
    private ControlCommand() {
        al = new ArrayList<>();
        player = MakhlukPlayer.getPlayer();
        al.add(player);
        MakhlukSpawn ms = new MakhlukSpawn(al);
        ms.spawnMakhlukAntiAir(DEFAULT_MAKHLUK_SPAWNED);
        ms.spawnMakhlukBurukRupa(DEFAULT_MAKHLUK_SPAWNED);
        ms.spawnMakhlukMaling(DEFAULT_MAKHLUK_SPAWNED);
        ms.spawnMakhlukMonster(DEFAULT_MAKHLUK_SPAWNED2);
        ms.spawnMakhlukTerbang(DEFAULT_MAKHLUK_SPAWNED);
        board = new Board(al);
        start();
    }
    /** Return Commander Address.
     * @return cc Commander Address
     */
    public static ControlCommand commander() {
        return cc;
    }

    @Override
    public final void run() {
        final int fivety = 50;
        try {
            while (player.getAlive() && !MakhlukPlayer.getMPlayer().getWin()) {
                for (int i = 0; i < al.size(); i++) {
                    Makhluk m = al.get(i);
                    if (!m.getAlive()) {
                        al.remove(m);
                        i--;
                    }
                }
                checkCollision();
                checkPlayer();
                checkWin();
                Thread.sleep(fivety);
            }
        } catch (InterruptedException e) {
            //System.out.println("my thread interrupted");
        }
    }

    /**returning array list in command control.
     * @return al */
    public final ArrayList<Makhluk> getArrayList() {
        return al;
    }

    /**returning board in command control.
     * @return board */
    public final Board getBoard() {
        return board;
    }

    /**check collision of makhluks.*/
    public final void checkCollision() {
        final int top = 15;
        for (int i = 0; i < al.size(); i++) {
            Makhluk m = al.get(i);
            int x = m.getX();
            int y = m.getY();
            for (int j = 0; j < al.size(); j++) {
                Makhluk m2 = al.get(j);
                if (m != m2) {
                    int x2 = m2.getX();
                    int y2 = m2.getY();
                    if ((Math.abs(x - x2) < top) && (Math.abs(y - y2) < top)) {
                        m.fight(m2);
                        if (m.gettype() == 0) {
                            if (MakhlukPlayer.getMPlayer().getAlive()) {
                                MakhlukPlayer.playerEat();
                            }
                            board.updateScore(MakhlukPlayer.score());
                        }
                    }
                }
            }
        }
    }
    /** Checking player position. */
    public final void checkPlayer() {
        final int left = 20;
        final int right = 650;
        final int top = 120;
        final int bottom = 640;
        if (player.getX() < left) {
            MakhlukPlayer.playerRight();
            MakhlukPlayer.getMPlayer().move();
        } else if (player.getX() > right) {
            MakhlukPlayer.playerLeft();
            MakhlukPlayer.getMPlayer().move();
        } else if (player.getY() < top) {
            MakhlukPlayer.playerDown();
            MakhlukPlayer.getMPlayer().move();
        } else if (player.getY() > bottom) {
            MakhlukPlayer.playerUp();
            MakhlukPlayer.getMPlayer().move();
        }
    }
    /** Winner condition (36 in ArrayList). */
    public final void checkWin() {
        final int banyakMakhlukMonster = 36;
        if (al.size() == banyakMakhlukMonster) {
            MakhlukPlayer.getMPlayer().setWin(true);
        }
    }
}
