// Server_Socket.cpp : Defines the entry point for the application.
//

#include "server_socket.h"

using namespace std;

Server::Server() {
    
}

int Server::Start_Server() {
    //main locals
    WSAData WinSockData;
    WORD DLLVERSION;
    char MESSAGE[12];
    

    //WORDS = objects of a data size that a processor naturally handles (such as 16 or 32-bit)
    DLLVERSION = MAKEWORD(2, 1); //macro to create WORD value by concatenating its arguments

    //Start Winsock DLL
    Server::set_SUCC(WSAStartup(DLLVERSION, &WinSockData)) ;

    //Create Socket Structure
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    //Create Sockets
    SOCKET sock_LISTEN; //listen for incoming connection
     //active if connection found

    //socket Arguments: AF_INET = internet domain,
    //SOCK_STREAM = connection oriented with TCP
    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, 0);
    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); //Set IP
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(4444); //port

    sock_LISTEN = socket(AF_INET, SOCK_STREAM, 0);
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
    listen(sock_LISTEN, SOMAXCONN); //listen without limits
    Server::get_obs().start_mix();


    //If connection found:
    for (;;)
    {
        cout << "\n\tSERVER: WAITING for incoming connection...";
        if (Server::set_sock_CON( accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)))
        {
            cout << "\n\tA connection found!" << endl;
            cout << "\n\t Writing to client..." << endl;
            //send(Server::get_sock_CON(), "Welcome! You have connected to Banana SERVER!", 46, 0);
            Server::write_to_client("Welcome! You have connected to Banana SERVER!");
            cout << "\n\t sent!" << endl << endl;
            cout << "\n\t Receiving Player name from Client" << endl;
            Server::set_SUCC(recv(Server::get_sock_CON(), MESSAGE, sizeof(MESSAGE), 0));
            Server::set_converter(MESSAGE) ;
            player1.setName(Server::get_converter());
            Server::set_SUCC(recv(Server::get_sock_CON(), MESSAGE, sizeof(MESSAGE), 0));
            Server::set_converter(MESSAGE);
            player2.setName(Server::get_converter());
            cout << "\n\t MESSAGE FROM THE CLIENT: " << endl;
            Server::print_names();
            Server::keepReading();
            
        }
    }
    return 1;
}
void Server::set_converter(string new_con) {
    Server::converter = new_con;
};
string Server::get_converter() {
    return Server::converter;
};
void Server::keepReading() {
    while (true) {
        char MESSAGE[12];
        cout << "\n\t Ready!" << endl;
        Server::set_SUCC(recv(Server::get_sock_CON(), MESSAGE, sizeof(MESSAGE), 0));
        Server::set_converter(MESSAGE);
        cout << "\n\t new command:" << Server::get_converter()<<endl;
        Server::write_to_client(Server::get_obs().Read_Action(Server::get_converter()));
        cout << "\n\t Response sent"<< endl;
    }
}

void Server::set_SUCC(long new_SUCC) {
    Server::SUCCESFUL = new_SUCC;
};
long Server::get_SUCC() {
    return Server::SUCCESFUL;
};
int Server::set_sock_CON(SOCKET new_Sock) {
    Server::sock_CONNECTION = new_Sock;
    return 1;
};
SOCKET Server::get_sock_CON() {
    return Server::sock_CONNECTION;
};
void Server::set_player1(Player new_player1) {
    Server::player1 = new_player1;
};
Player Server::get_player1() {
    return Server::player1;
};
void Server::set_player2(Player new_player2) {
    Server::player2 = new_player2;
};
Player Server::get_player2() {
    return Server::player2;
};
void Server::print_names() {
    Player name1 = Server::get_player1();
    Player name2 = Server::get_player2();
    cout << "\t "<<name1.get_name() << endl;
    cout << "\t" << name2.get_name() << endl;
};

void Server::write_to_client(string message) {
    
    const char* message_buf[10]{message.c_str()};
    message_buf;
    send(Server::get_sock_CON(), *message_buf, message.length(), 0);
}
string Server::read_from_client() {
    char MESSAGE[10];
    cout << "ready";
    Server::set_SUCC(recv(Server::get_sock_CON(), MESSAGE, sizeof(MESSAGE), 0));
    Server::set_converter(MESSAGE);
    return Server::get_converter();
}
Observer Server::get_obs() {
    return Server::observer;
}
void Server::set_obs(Observer new_obs) {
    Server::observer = new_obs;
}

