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

    JLabel label;
    JLabel label1;
    JLabel label2;
    JLabel label3;
    JLabel label4;
    JLabel label5;
    JLabel label6;
    JLabel label7;
    ControlCommand C;

    /**
     * Konstruktor
     * @param s masukan string yang dibutuhkan untuk window title
     * @param _c masukan sebagai objek yang akan diubah
     */
    public KeyListenerForMe(String s, ControlCommand _c) {
        super(s);
        JPanel p = new JPanel();
        label  = new JLabel("Key Listener!");
        label1 = new JLabel("Key Command In Key Listener =                                 " );
        label2 = new JLabel("- Space         = Pause                                       " );
        label3 = new JLabel("- Right         = Step by Step/resume + Step by Step if paused" );
        label4 = new JLabel("- ESC           = Exit                                        " );
        label5 = new JLabel("- R             = Resume                                      " );
        label6 = new JLabel("- PrintScreen   = Screenshot                                  " );
        label7 = new JLabel("- S             = Spawn Monster                               ");
        p.add( label);
        p.add( label1);
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
        this.C = _c;
    }

    @Override
    public void keyTyped(KeyEvent e) {

       
    }

    @Override
    public void keyPressed(KeyEvent e) {

        if(e.getKeyCode()==KeyEvent.VK_SPACE){
          //  System.out.println("Press R to Continue .... ");
            C.Pause = true;
         //   System.out.println("Press R to Continue .... ");
        }
        if(e.getKeyCode()==KeyEvent.VK_ESCAPE){
            C.Exit = true;
            C.Pause = false;
        }
        if(e.getKeyCode() == KeyEvent.VK_L){
            C.Screenshot = true;
            C.Pause = false;
        }
        if(e.getKeyCode()==KeyEvent.VK_R){
            //System.out.println("Start .. ");
            C.Pause = false;
        }
        if(e.getKeyCode()==KeyEvent.VK_RIGHT){
            C.Step = true;
            C.Pause = false;
        }
        if(e.getKeyCode()==KeyEvent.VK_S){
            //System.out.println("Start .. ");
            C.Spawn = true;
            C.Pause = false;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        
    }
}
