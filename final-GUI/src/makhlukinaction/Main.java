package makhlukinaction;

import javax.swing.JFrame;

/**
 * @author Joshua Salimin - 13514001
 */
public class Main {
    /** Main Program.
     * @param args Some argument. */
    public static void main(final String[] args) {
        final int magic = 700;
        JFrame jf = new JFrame();
        jf.add(ControlCommand.commander().getBoard());
        jf.setVisible(true);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jf.setSize(magic, magic);
    }
}
