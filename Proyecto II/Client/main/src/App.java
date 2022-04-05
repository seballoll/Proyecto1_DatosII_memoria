
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFrame;  

public class App implements WindowListener,ActionListener{  
    Client_Socket cliente_actual;
public static void main(String[] args) {  
    App escuchar = new App();
JFrame f=new JFrame();//creating instance of JFrame  
          
JButton b=new JButton("click");//creating instance of JButton  

b.addActionListener(escuchar);
b.setBounds(130,100,100, 40);//x axis, y axis, width, height  
          
f.add(b);//adding button in JFrame  
          
f.setSize(400,500);//400 width and 500 height  
f.setLayout(null);//using no layout managers  
f.setVisible(true);//making the frame visible  

}  
static Client_Socket connect_socket(){
    System.out.println("opening socket...");
    Client_Socket cliente = new Client_Socket();
    cliente.start_client();
    System.out.println("socket conected");
    
    return cliente;
}
public void actionPerformed(ActionEvent e){
    String action = e.getActionCommand();
    if(action=="click"){
    System.out.println(action);
    System.out.println("boton click");
    cliente_actual=connect_socket();
    try {
        System.out.println("reading from server"+"\n");
        cliente_actual.read_server();
    } catch (ClassNotFoundException e1) {
        System.out.println("class exception");
        e1.printStackTrace();
    } catch (IOException e1) {
        System.out.println("Io exception");
        e1.printStackTrace();
    }
    System.out.println("Writing to server");
    cliente_actual.Write_server("pepito");
    
    System.out.println("Message sent");
    }
}
@Override
public void windowOpened(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowClosing(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowClosed(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowIconified(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowDeiconified(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowActivated(WindowEvent e) {
    // TODO Auto-generated method stub
    
}
@Override
public void windowDeactivated(WindowEvent e) {
    // TODO Auto-generated method stub
    
}


}  