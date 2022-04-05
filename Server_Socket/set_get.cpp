#include "set_get.h"

using namespace std;


Player::Player(string theName, int points) : name(theName), points(-1) {
    set_points(points);
    setName(theName);
}

// accessor
string Player::get_name() const {
    return name;
}
void Player::setName(string NewName) {
    Player::name = NewName;
}
int Player::getPoints() const
{
    return points;
}

void Player::set_points(int newPoints)
{
    Player::points = newPoints;
}
// mutator
void Player::print_info() {
    cout <<"name: " << get_name() << endl << "points: " << getPoints();
}




