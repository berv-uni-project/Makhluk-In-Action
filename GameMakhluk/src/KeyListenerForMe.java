import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


/**
 * @author M. Az-zahid Adhitya Silparensi-13514095
 */
public final class KeyListenerForMe extends JFrame implements KeyListener {
    /**
    * a merupakan sebuah variabel untuk set size.
    */
    final int a = 400;
    /**
    * b merupakan sebuah variabel untuk set size.
    */
    final int b = 300;
    /**
    * Jlabel berisi String Key Listener.
    */
    private JLabel label;
    /**
    * Jlabel berisi String.
    */
    private JLabel label1;
    /**
    * Jlabel berisi String.
    */
    private JLabel label2;
    /**
    * Jlabel berisi String.
    */
    private JLabel label3;
    /**
    * Jlabel berisi String.
    */
    private JLabel label4;
    /**
    * Jlabel berisi String.
    */
    private JLabel label5;
    /**
    * Jlabel berisi String.
    */
    private JLabel label6;
    /**
    * Jlabel berisi String.
    */
    private JLabel label7;
    /**
    * C merupakan sebuah ControlCommand.
    */
    private ControlCommand cC;

    /**
     * Konstruktor.
     * @param s masukan string yang dibutuhkan untuk window title
     * @param c masukan sebagai objek yang akan diubah
     */
    public KeyListenerForMe(final String s, final ControlCommand c) {
        super(s);
        JPanel p = new JPanel();
        label  = new JLabel("Key Listener!");
        label1 = new JLabel(
        "Key Command In Key Listener =                                 ");
        label2 = new JLabel(
        "- Space         = Pause                                       ");
        label3 = new JLabel(
        "- Right         = Step by Step/resume + Step by Step if paused");
        label4 = new JLabel(
        "- ESC           = Exit                                        ");
        label5 = new JLabel(
        "- R             = Resume                                      ");
        label6 = new JLabel(
        "- PrintScreen   = Screenshot                                  ");
        label7 = new JLabel(
        "- S             = Spawn Monster                               ");
        p.add(label);
        p.add(label1);
        p.add(label2);
        p.add(label3);
        p.add(label4);
        p.add(label5);
        p.add(label6);
        p.add(label7);
        add(p);
        addKeyListener(this);
        setSize(a, b);
        setVisible(true);
        this.cC = c;
    }

    @Override
    public void keyTyped(final KeyEvent e) {
    }

    @Override
    public void keyPressed(final KeyEvent e) {

        if (e.getKeyCode() == KeyEvent.VK_SPACE) {
          //  System.out.println("Press R to Continue .... ");
            cC.setPause(true);
         //   System.out.println("Press R to Continue .... ");
        }
        if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
            cC.setExit(true);
            cC.setPause(false);
        }
        if (e.getKeyCode() == KeyEvent.VK_L) {
            cC.setScreenshot(true);
            cC.setPause(false);
        }
        if (e.getKeyCode() == KeyEvent.VK_R) {
            //System.out.println("Start .. ");
            cC.setPause(false);
        }
        if (e.getKeyCode() == KeyEvent.VK_N) {
            cC.setStep(true);
            cC.setPause(false);
        }
        if (e.getKeyCode() == KeyEvent.VK_S) {
            //System.out.println("Start .. ");
            cC.setSpawn(true);
            cC.setPause(false);
        }
        if (e.getKeyCode() == KeyEvent.VK_UP) {
          //  System.out.println("Press R to Continue .... ");
            MakhlukPlayer.playerUp();
         //   System.out.println("Press R to Continue .... ");
        }
        if (e.getKeyCode() == KeyEvent.VK_DOWN) {
          //  System.out.println("Press R to Continue .... ");
            MakhlukPlayer.playerDown();
         //   System.out.println("Press R to Continue .... ");
        }
        if (e.getKeyCode() == KeyEvent.VK_LEFT) {
          //  System.out.println("Press R to Continue .... ");
            MakhlukPlayer.playerLeft();
         //   System.out.println("Press R to Continue .... ");
        }
        if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
          //  System.out.println("Press R to Continue .... ");
            MakhlukPlayer.playerRight();
         //   System.out.println("Press R to Continue .... ");
        }
    }

    @Override
    public void keyReleased(final KeyEvent e) {
    }
}
