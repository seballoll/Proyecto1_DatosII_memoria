


import java.awt.*;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class App {  
    static client_Listen action_listener;
    JTextField t1;
    JTextField t2;
    JFrame f;

public void setAction_listener(client_Listen action_listener) {
    App.action_listener = action_listener;
}
public static client_Listen getAction_listener() {
    return action_listener;
}

public void Start_Screen() throws IOException{
    
f=new JFrame("entrada");//creating instance of JFrame  
JLayeredPane bkgrnd = f.getLayeredPane();


JLabel l1 = new JLabel("Juego de Memoria!");
JLabel l2 = new JLabel("\n\t" +"Busque las parejas de las tarjetas");
t1 = new JTextField("nombre");
t2 = new JTextField("nombre");
JButton b=new JButton("Empezar");//creating instance of JButton  
b.addActionListener(action_listener);
l1.setBounds(200, 100, 200, 40);
l2.setBounds(200, 200, 400, 40);
t1.setBounds(200, 350, 100, 30);
t2.setBounds(310,350,100,30);
b.setBounds(200,400,100, 40);//x axis, y axis, width, height  
bkgrnd.add(l1,1);
bkgrnd.add(t1,1);
bkgrnd.add(l2,1);
bkgrnd.add(t2,1);
bkgrnd.add(b);//adding button in JFrame  
f.setSize(600,700);//400 width and 500 height  
f.setLayout(null);//using no layout managers  
f.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("main/src/Images/Background.png"))))); 
f.setVisible(true);//making the frame visible  
f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
public void start_game() throws IOException{
    f.setVisible(false);
    f = new JFrame("juego");
    JLayeredPane bkgrnd = f.getLayeredPane();
    
    JLabel l1 = new JLabel("Jugador 1:");
    JLabel l2 = new JLabel("Jugador 2:");
    JLabel N1 = new JLabel(t1.getText());
    JLabel N2 = new JLabel(t2.getText());
    l1.setBounds(200, 550, 100, 30);
    bkgrnd.add(l1);
    l2.setBounds(400, 550, 100, 30);
    bkgrnd.add(l2);
    N1.setBounds(200, 600, 100, 30);
    bkgrnd.add(N1);
    N2.setBounds(400, 600, 100, 30);
    bkgrnd.add(N2);
    
    JPanel panel = new JPanel();
    panel.setBounds(0,0,900,500);

    JButton card1 = new JButton("1");
    JButton card2 = new JButton("2");
    JButton card3 = new JButton("3");
    JButton card4 = new JButton("4");
    JButton card5 = new JButton("5");
    JButton card6 = new JButton("6");
    JButton card7 = new JButton("7");
    JButton card8 = new JButton("8");
    JButton card9 = new JButton("9");
    JButton card10 = new JButton("10");
    JButton card11 = new JButton("11");
    JButton card12 = new JButton("12");
    ImageIcon cardIcon =new ImageIcon(ImageIO.read(new File("main/src/Images/Card.png")));
    card1.setIcon(cardIcon);
    card2.setIcon(cardIcon);
    card3.setIcon(cardIcon);
    card4.setIcon(cardIcon);
    card5.setIcon(cardIcon);
    card6.setIcon(cardIcon);
    card7.setIcon(cardIcon);
    card8.setIcon(cardIcon);
    card9.setIcon(cardIcon);
    card10.setIcon(cardIcon);
    card11.setIcon(cardIcon);
    card12.setIcon(cardIcon);
    
    //card1.setName("1");
    card1.addActionListener(action_listener);
    card2.addActionListener(action_listener);
    card3.addActionListener(action_listener);
    card4.addActionListener(action_listener);
    card5.addActionListener(action_listener);
    card6.addActionListener(action_listener);
    card7.addActionListener(action_listener);
    card8.addActionListener(action_listener);
    card9.addActionListener(action_listener);
    card10.addActionListener(action_listener);
    card11.addActionListener(action_listener);
    card12.addActionListener(action_listener);

    panel.add(card1);panel.add(card2);panel.add(card3);panel.add(card4);panel.add(card5);panel.add(card6);panel.add(card7);panel.add(card8);
    panel.add(card9);panel.add(card10);panel.add(card11);panel.add(card12);
    panel.setLayout(new GridLayout(3,4));
    bkgrnd.add(panel,1);
    

    f.setSize(900,700);//400 width and 500 height  
    f.setLayout(null);//using no layout managers 
    f.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("main/src/Images/Background.png"))))); 
    f.setVisible(true);//making the frame visible  
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}


}  