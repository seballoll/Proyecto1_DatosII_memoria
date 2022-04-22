#pragma once
#ifndef Starter_H
#define Starter_H

#include <string>
#include <iostream>
#include "Player.h"
#include "Server_Socket.h"
#include "cards.h"
#include "Observer.h"
#include "Actions.h"
#include <thread>



using namespace std;

class Starter{
    Player player_object1;
    Player player_object2;
    Server socket_object;
    Observer observer_object;
    Action serv_obs;
    

public:
    Starter();

    
};


#endif // SET_GET_H
