#pragma comment(lib, "Ws2_32.lib")

//STD console header files
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <string>



//SOCKET header files
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

class Server {
	long SUCCESFUL;
	SOCKET sock_CONNECTION;
public:
	Server();
	
	void set_SUCC(long new_SUCC);
	long get_SUCC();
	int set_sock_CON(SOCKET new_Sock);
	SOCKET get_sock_CON();
	void Start_Server() ;
	void keep_reading() ;
	

};


#define SCKVERSION2 0x0202


