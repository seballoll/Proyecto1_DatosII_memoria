#pragma once
#ifndef Server_H
#define Server_H
#define SCKVERSION2 0x0202

// DEBUG


#pragma comment(lib, "Ws2_32.lib")

//STD console header files
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <string>
//Player class
#include "Player.h"

//SOCKET header files
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include "Observer.h"


class Server {
	long SUCCESFUL;
	SOCKET sock_CONNECTION;
	Player player1;
	Player player2;
	string converter;
	Observer observer;


public:
	Server();

	void set_SUCC(long new_SUCC);
	long get_SUCC();
	int set_sock_CON(SOCKET new_Sock);
	SOCKET get_sock_CON();
	int Start_Server();
	void set_player1(Player new_player1);
	Player get_player1();
	void set_player2(Player new_player1);
	Player get_player2();
	void set_converter(string new_con);
	string get_converter();
	void print_names();
	void keepReading();
	void set_obs(Observer new_obs);
	Observer get_obs();

	void write_to_client(string messasge);
	string read_from_client();

};




#endif 
