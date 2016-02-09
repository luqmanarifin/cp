//FirstSwingListener.java
import javax.swing.*;
import java.awt.event.*;
public class FirstSwingListener extends JFrame {
  public FirstSwingListener(String title) {
    super(title);
  }
  public static void main(String s[]) {
    FirstSwingListener frame = new FirstSwingListener("First Swing Application");
    frame.addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        JOptionPane.showMessageDialog(null, "Window Closing","Information", 0);
        System.exit(0);
      }
    });
    frame.setSize(50,100);
    frame.show();
  }
} 