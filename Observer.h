#pragma once
#ifndef myObserver_H
#define myObserver_H

#include <string>
#include <iostream>
#include "Player.h"
#include "cards.h"
#include "Disk.h"
#include "Actions.h"
#include <thread>
#include <map>



//using namespace std;

class Observer {
    Player player_object1;
    Player player_object2;
    //Server socket_object;
    Cards game[12];
    Disk DiskFile;
    string last_action;
    int turn;


public:
    Observer();
    Observer(Observer*);

    // accessor
    void start_mix();

    Player get_player1();
    Player get_player2();
    //Server get_Server();
    Disk get_Disk();
    string get_last();
    Cards* get_game();
    void iniciar_obs();
    
    void set_game(Cards& new_game);
    void set_Player1(Player& new_player);
    void set_Player2(Player& new_player);
    //void set_Server(Server& new_Server);
    void set_DiskFile(Disk& new_Disk);
    
    void set_last(string new_act);
    void set_act(Action& new_act);
    // mutator
    void Print_observer();
    string Read_Action(string action);

    bool check_num(int i,int used_nums[]);
    
    
};


#endif // SET_GET_H
