package makhlukinaction;

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
public class KeyListenerForMe extends JFrame implements KeyListener {

    /**
     *
     */
    private static final long serialVersionUID = 5432112345L;
    private final JLabel label;
    private final JLabel label1;
    private final JLabel label2;
    private final JLabel label3;
    private final JLabel label4;
    private final JLabel label5;
    private final JLabel label6;
    private final JLabel label7;
    private final ControlCommand _controlCommand;

    /**
     * Konstruktor
     * 
     * @param stringWindow  masukan string yang dibutuhkan untuk window title
     * @param _controlCommand masukan sebagai objek yang akan diubah
     */
    public KeyListenerForMe(String stringWindow, ControlCommand _controlCommand) {
        super(stringWindow);
        JPanel p = new JPanel();
        label = new JLabel("Key Listener!");
        label1 = new JLabel("Key Command In Key Listener =                                 ");
        label2 = new JLabel("- Space         = Pause                                       ");
        label3 = new JLabel("- Right         = Step by Step/resume + Step by Step if paused");
        label4 = new JLabel("- ESC           = Exit                                        ");
        label5 = new JLabel("- R             = Resume                                      ");
        label6 = new JLabel("- PrintScreen   = Screenshot                                  ");
        label7 = new JLabel("- S             = Spawn Monster                               ");
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
        setSize(400, 300);
        setVisible(true);
        this._controlCommand = _controlCommand;
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_SPACE) {
            _controlCommand.pause = true;
        }
        if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
            _controlCommand.exit = true;
            _controlCommand.pause = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_L) {
            _controlCommand.screenshot = true;
            _controlCommand.pause = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_R) {
            _controlCommand.pause = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
            _controlCommand.step = true;
            _controlCommand.pause = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_S) {
            _controlCommand.spawn = true;
            _controlCommand.pause = false;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
