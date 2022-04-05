import java.io.*;
import java.net.*;

public class Client_Socket implements Serializable {
    static Socket s;
    static String username ;
    static InputStreamReader RD;
    static BufferedReader BFRD;
    static PrintWriter WRT;
    static BufferedWriter BFWRT;
    /**
     * starts client
     * @throws IOException
     */


    /**
     * pone el nombre del jugador
     */
    public void setName(String name){
        username = name;
    }
    public void start_client(){
        try {
            s = new Socket("LocalHost",4444);
        } catch (IOException e) {
            System.out.println("Socket cant connect");
            e.printStackTrace();
        }
        try {
            RD = new InputStreamReader(s.getInputStream());
        } catch (IOException e) {
           System.out.println("input stream error");
            e.printStackTrace();
        }
        BFRD = new BufferedReader(RD);
        try {
            WRT = new PrintWriter(s.getOutputStream());
        } catch (IOException e) {
            System.out.println("output stream error");
            e.printStackTrace();
        }
        BFWRT = new BufferedWriter(WRT);
        
    }

    /**
     * recibe el tablero enviado desde el servidor
     * @throws IOException
     * @throws ClassNotFoundException
     */
    public  void read_server() throws IOException, ClassNotFoundException {
        
        char[] message = new char[128];
       int text = RD.read(message,0,message.length);
       System.out.println(String.valueOf(message)+"\n"+"amount of bytes= "+text);
    }
    public void Write_server(String message){
            try {
                BFWRT.write(message, 0, message.length());
                BFWRT.flush();
            } catch (IOException e) {
                System.out.println("writer error");
                e.printStackTrace();
            }
    }
    public void Receive_ser_pos() throws IOException, ClassNotFoundException {
       

    }
    public  void Send_client_pos(int[] client_pos) throws IOException {
        ObjectOutputStream OOSTR = new ObjectOutputStream(s.getOutputStream());
        OOSTR.writeUnshared(client_pos);

    }


}