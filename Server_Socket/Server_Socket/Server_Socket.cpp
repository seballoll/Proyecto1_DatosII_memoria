// Server_Socket.cpp : Defines the entry point for the application.
//

#include "server_socket.h"
#include "Player.h"
using namespace std;

Server::Server() {
    
}

void Server::Start_Server() {
    //main locals
    
    WSAData WinSockData;
    WORD DLLVERSION;
    char MESSAGE[12];
    string converter;

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



    //If connection found:
    for (;;)
    {
        cout << "\n\tSERVER: WAITING for incoming connection...";
        if (Server::set_sock_CON( accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)))
        {
            cout << "\n\tA connection found!" << endl;
            cout << "\n\t Writing to client..." << endl;
            send(Server::get_sock_CON(), "Welcome! You have connected to Banana SERVER!", 46, 0);
            cout << "\n\t sent!" << endl << endl;
            cout << "\n\t Receiving Player name from Client" << endl;
            Server::set_SUCC(recv(Server::get_sock_CON(), MESSAGE, sizeof(MESSAGE), 0));
            converter = MESSAGE;
            cout << "\n\t MESSAGE FROM THE CLIENT: " << endl << "\n\t"<<converter;
            this->keep_reading();

        }
    }
   
}
void Server::keep_reading() {
    cout << "\n\t Server kept reading"<<endl;
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


