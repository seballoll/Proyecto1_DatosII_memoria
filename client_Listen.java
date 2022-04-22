import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
public class client_Listen implements WindowListener,ActionListener {
    Client_Socket cliente_actual;
    String player_name;
    App ventana;
    

	@Override
	public void actionPerformed(ActionEvent e) {
        System.out.println(e.getActionCommand());
        String username1 = ventana.t1.getText();
        String username2 = ventana.t2.getText();
		String action = e.getActionCommand();
        if (action =="Empezar"){
            System.out.println(action);
        
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
            cliente_actual.Write_server(username1);
            cliente_actual.Write_server(username2);
        
            System.out.println("Message sent");
            try {
                ventana.start_game();
            } catch (IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        
    } 
        if( action=="1"){
            
            cliente_actual.Write_server("boton1");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }if( action=="2"){ 
            cliente_actual.Write_server("boton2");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="3"){ 
            
            cliente_actual.Write_server("boton3");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="4"){ 
            
            cliente_actual.Write_server("boton4");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="5"){ 
            cliente_actual.Write_server("boton5");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }if( action=="6"){ 
            cliente_actual.Write_server("boton6");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="7"){ 
            cliente_actual.Write_server("boton7");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="8"){ 
            cliente_actual.Write_server("boton8");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }if( action=="9"){ 
            cliente_actual.Write_server("boton9");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }
        }if( action=="10"){ 
            cliente_actual.Write_server("boton10");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="11"){ 
            cliente_actual.Write_server("boton11");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

        }if( action=="12"){ 
            cliente_actual.Write_server("boton12");
            try {
                String _imagen =cliente_actual.read_server();
                Open_server_image(_imagen);

            } catch (ClassNotFoundException | IOException e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }

    }
    
		}
    public void setCliente_actual(Client_Socket cliente_actual) {
        this.cliente_actual = cliente_actual;
    }
    public Client_Socket getCliente_actual() {
        return cliente_actual;
    }
    public void setPlayer_name(String player_name) {
        this.player_name = player_name;
    }public String getPlayer_name() {
        return player_name;
    }
    public void setVentanaaApp(App ventanaaApp) {
        this.ventana = ventanaaApp;
    }
    public App getVentanaaApp() {
        return ventana;
    }
    public void Open_server_image(String image) throws  IOException{
        System.out.println("imagen: "+image);
        
        if("Puffins".equals(new String(image))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/Puffins.jpg"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }if(image.equals(new String("Perico"))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/Perico.jpeg"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }if(image.equals(new String("Parrot"))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/Parrot.png"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }if(image.equals(new String("Robin"))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/Robin.png"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }if(image.equals(new String("White"))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/White.png"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }if(image.equals(new String("Yellow"))){
            
            JFrame image_open = new JFrame("imagen");
            BufferedImage bufimage = ImageIO.read(new File("main/src/images/Yellow.png"));
            ImageIcon new_image = new ImageIcon(bufimage);
            JLabel lbl = new JLabel();
            lbl.setIcon(new_image);
            image_open.add(lbl);
            image_open.pack();
            image_open.setSize(500,500);
            image_open.setVisible(true);
        }
        
        
        System.out.println("out ifs");

        
    }

    //public boolean check_string(String new_type,String type){
        
    //}

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

    Client_Socket connect_socket(){
        System.out.println("opening socket...");
        Client_Socket cliente = new Client_Socket();
        cliente.start_client();
        System.out.println("socket conected");
        
        return cliente;
    }
    
}
