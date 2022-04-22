#include "Observer.h"


//using namespace std;


    


Observer::Observer() {
    Player player_object1;
    Player player_object2;
    string last_action;
    int turn =0;
    Cards game[12]{ };
    
}
   

    // accessor
Player Observer::get_player1() {
    return Observer::player_object1;
    };
Player Observer::get_player2() {
    return Observer::player_object2;
};

void Observer::set_Player1(Player& new_player) {
    Observer::player_object1 = new_player;
    };
void Observer::set_Player2(Player& new_player) {
    Observer::player_object2 = new_player;
};



Disk Observer::get_Disk() {
    return Observer::DiskFile;
}
void Observer::set_DiskFile(Disk& new_Disk) {
    Observer::DiskFile = new_Disk;
}


string Observer::Read_Action(string action) {
    if(Observer::turn == 1){}

    if (action == "boton1") {
        
        cout << "\n\t el boton 1 fue presionado";
        Observer::last_action = "boton1";

        cout <<"\n\t" << this->game;
        cout << "\n\t a " << Observer::game->getFile();
        //return Observer::game[0].getFile();
        return "Robin";
    }
    if (action == "boton2") {
        Observer::last_action = "boton2";
        cout << "\n\t el boton 1 fue presionado";
        return "Puffins";
    }
    if (action == "boton3") {
        
        cout << "\n\t el boton 3 fue presionado";
        return "Parrot";
    }
    if (action == "boton4") {
        
        cout << "\n\t el boton 4 fue presionado";
        return "imagen en pos 4";
    }if (action == "boton5") {
        
        cout << "\n\t el boton 5 fue presionado";
        return "Robin";
    }if (action == "boton6") {
        
        cout << "\n\t el boton 6 fue presionado";
        return "White";
    }if (action == "boton7") {
        
        cout << "\n\t el boton 7 fue presionado";
        return "Yellow";
    }if (action == "boton8") {
        
        cout << "\n\t el boton 8 fue presionado";
        return "imagen en pos 8";
    }if (action == "boton9") {
        
        cout << "\n\t el boton 9 fue presionado";
        return "imagen en pos 9";
    }if (action == "boton10") {
        
        cout << "\n\t el boton 10 fue presionado";
        return "imagen en pos 10";
    }if (action == "boton11") {

        cout << "\n\t el boton 11 fue presionado";
        return "imagen en pos 11";
    }if (action == "boton12") {

        cout << "\n\t el boton 12 fue presionado";
        return "imagen en pos 12";
    }
    return "a";
}
void Observer::set_last(string new_act) {
    Observer::last_action = new_act;
}
string Observer::get_last() {
    return Observer::last_action;
}

Cards* Observer::get_game() {
    return Observer::game;
}
void Observer::set_game(Cards& new_game) {
    *Observer::game = new_game;
}

void Observer::start_mix() {
    int counter = 0;
    bool is_mixed = false;
    int used_numarr[11];
    cout << "\n\t" << this->game<<endl;
    
    srand((unsigned)time(0));
    while (!is_mixed) {
        if (counter>= 12) {
            break;
        }
        
        int temp = rand() % 12+1;
        

        if(!Observer::check_num(temp,used_numarr)) {
            used_numarr[counter] = temp;
            counter++;
        }
        
    }
    

    map<int, string> Files_map{
        {1,"Parrot"},
        {2,"Yellow"},
        {3,"Perico"},
        {4,"Puffins"},
        {5,"White"},
        {6,"Robin"}

    };
    bool done_pair = false;;
    int file_count = 1;

    for (size_t z = 0; z <= 11; z++)
    {
        //cout << file_count;
        Cards cardz;
        cardz.setFile(Files_map[file_count]);
        //cout << "Z>" << used_numarr[z];
        int temp = used_numarr[z]-1;

        Observer::game[temp] = cardz;
        //cout << cardz.getFile();
        if (done_pair) {
            if (file_count < 11) {
                file_count++;
                done_pair = false;
            }
            else {

            }
        }
        else {
            done_pair = true;
        }
    }
    for (size_t x = 0; x <= 11; x++)
    {
        cout <<"observer>"<<x<<" " << Observer::game[x].getFile() << endl;
        
    }
    
}

bool Observer::check_num(int i, int used_num[]) {
    for (size_t j = 0; j <= 12; j++)
    {
        if (i == used_num[j]) {
            return true;
            break;
        }
    }
    return false;
}




