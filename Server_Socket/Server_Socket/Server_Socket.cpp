// Server_Socket.cpp : Defines the entry point for the application.
//

#include "server_socket.h"
#include "set_get.h"
using namespace std;

int main()
{
    //main locals
    long SUCCESSFUL;
    WSAData WinSockData;
    WORD DLLVERSION;
    char MESSAGE[12];
    string converter;

    //WORDS = objects of a data size that a processor naturally handles (such as 16 or 32-bit)
    DLLVERSION = MAKEWORD(2, 1); //macro to create WORD value by concatenating its arguments

    //Start Winsock DLL
    SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

    //Create Socket Structure
    SOCKADDR_IN ADDRESS;
    int AddressSize = sizeof(ADDRESS);

    //Create Sockets
    SOCKET sock_LISTEN; //listen for incoming connection
    SOCKET sock_CONNECTION; //active if connection found

    //socket Arguments: AF_INET = internet domain,
    //SOCK_STREAM = connection oriented with TCP
    sock_CONNECTION = socket(AF_INET, SOCK_STREAM, 0);
    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); //Set IP
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(4444); //port

    sock_LISTEN = socket(AF_INET, SOCK_STREAM, 0);
    bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
    listen(sock_LISTEN, SOMAXCONN); //listen without limits
    Player pepe{"",0 };
 


    //If connection found:
    for (;;)
    {
        cout << "\n\tSERVER: WAITING for incoming connection...";
        if ((sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)))
        {
            cout << "\n\tA connection found!" << endl;
            cout << "\n\t Writing to client..." << endl;
            SUCCESSFUL = send(sock_CONNECTION, "Welcome! You have connected to Banana SERVER!", 46, 0);
            cout << "\n\t sent!" << endl<<endl;
            cout << "\n\t Receiving Player name from Client" << endl;
            SUCCESSFUL = recv(sock_CONNECTION, MESSAGE, sizeof(MESSAGE), 0);
            converter = MESSAGE;
            cout << "\n\t MESSAGE FROM THE CLIENT: " << endl << converter;
            pepe.setName(converter);
            pepe.print_info();

        }
    }

    int send_message(); {

    }
}

