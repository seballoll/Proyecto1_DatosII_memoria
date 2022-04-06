#pragma once
#ifndef Starter_H
#define Starter_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Server_Socket.h"


using namespace std;

class Starter{
    Player player_Object;
    Server socket_object;

public:
    Starter();

    // accessor
    Player get_Player() const;
    Server get_Server();
    void set_Player(Player new_player);
    void set_Server(Server new_Server);

    // mutator
    

    void print_info();
};


#endif // SET_GET_H
