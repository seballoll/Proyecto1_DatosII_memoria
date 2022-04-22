import java.io.IOException;

public class Starter {
    static App base_app;
    static client_Listen base_listen;
    static Client_Socket base_socket;
    public static void main(String[] args) throws IOException{
        System.out.println("test");
        base_app=new App();
        base_listen = new client_Listen();
        base_socket = new Client_Socket();
        base_app.setAction_listener(base_listen);
        base_listen.setCliente_actual(base_socket);
        base_app.Start_Screen();
        base_listen.setVentanaaApp(base_app);
        
    }

    
}
