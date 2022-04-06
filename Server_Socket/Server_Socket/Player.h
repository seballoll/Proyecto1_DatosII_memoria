#ifndef Player_H
#define Player_H

#include <string>
#include <iostream>

using namespace std;

class Player {
//private:
    string name;
    int points;

public:
    Player(string theName, int points);

    // accessor
    string get_name() const;

    // mutator
    void set_points(int newPoints);

    friend ostream& operator<<(ostream& ostr, const Player& stud);
    int getPoints() const;
    void setName(string Name);
    void print_info();
};


#endif // SET_GET_H
