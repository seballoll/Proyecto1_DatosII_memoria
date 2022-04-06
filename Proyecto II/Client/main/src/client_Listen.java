import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.io.IOException;
public class client_Listen implements WindowListener,ActionListener {
    Client_Socket cliente_actual;
    String player_name;
    App ventana;

	@Override
	public void actionPerformed(ActionEvent e) {
        String username = ventana.t.getText();
        System.out.println(username);
		String action = e.getActionCommand();
        if (action =="Empezar");{
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
        cliente_actual.Write_server(username);
    
        System.out.println("Message sent");
    }if( action=="nombre"){
        
        

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
