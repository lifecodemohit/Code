import javax.swing.JFrame;

public class SizedFrameTest
{
public static void main(String[] args)
{
JFrame frame = new JFrame();
frame.setTitle("BasicFrame");
frame.setSize(300,400);
//frame.setIconImage(new ImageIcon("smiley.jpg").getImage());
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
frame.setVisible(true);
}
}