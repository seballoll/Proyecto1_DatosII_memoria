


import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class App {  
    static client_Listen action_listener;
    JTextField t;


public void setAction_listener(client_Listen action_listener) {
    App.action_listener = action_listener;
}
public static client_Listen getAction_listener() {
    return action_listener;
}

public void Start_Screen(){
    
JFrame f=new JFrame();//creating instance of JFrame  
JLabel l1 = new JLabel("Juego de Memoria!");
JLabel l2 = new JLabel("\n\t" +"Busque las parejas de las tarjetas");
t = new JTextField("nombre");
JButton b=new JButton("Empezar");//creating instance of JButton  
b.addActionListener(action_listener);
l1.setBounds(200, 100, 200, 40);
l2.setBounds(200, 200, 400, 40);
t.setBounds(200, 350, 300, 30);
b.setBounds(200,400,100, 40);//x axis, y axis, width, height  
f.add(l1);
f.add(l2);
f.add(t);
f.add(b);//adding button in JFrame  
f.setSize(600,700);//400 width and 500 height  
f.setLayout(null);//using no layout managers  
f.setVisible(true);//making the frame visible  
}



}  