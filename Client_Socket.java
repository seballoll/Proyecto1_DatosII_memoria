import java.io.*;
import java.net.*;
import java.util.Arrays;

public class Client_Socket implements Serializable {
    static Socket s;
    
    static InputStreamReader RD;
    static String MessageToServer;
    static PrintWriter WRT;
    static BufferedWriter BFWRT;
    static boolean  in_loop;
    /**
     * starts client
     * @throws IOException
     */


    /**
     * pone el nombre del jugador
     */
    
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
        
        try {
            WRT = new PrintWriter(s.getOutputStream());
        } catch (IOException e) {
            System.out.println("output stream error");
            e.printStackTrace();
        }
        BFWRT = new BufferedWriter(WRT);
        MessageToServer = null;
        
    }

    public void Start_loop(){
        
            if(MessageToServer == null){
                
                
            }
            else{
                String servermessage;
                System.out.println("writing");
                System.out.println(MessageToServer);
                Write_server(MessageToServer);
                MessageToServer = null;
                System.out.println("reading");
                try {
                    servermessage = read_server();
                    System.out.println(servermessage);
                } catch (ClassNotFoundException e) {
                    
                    e.printStackTrace();
                } catch (IOException e) {
                     
                    e.printStackTrace();
                }
                
            }
        }
    
 
    String read_server() throws IOException, ClassNotFoundException {
        
        char[] message = new char[128];
       int text = RD.read(message,0,message.length);
       char[] tempmessage =Arrays.copyOf(message,text);
       System.out.println(String.valueOf(message)+"\n"+"amount of bytes= "+text);
       return String.valueOf(tempmessage);
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
    
    public void set_messagetoserver(String new_message){
        MessageToServer = new_message;
    }

}