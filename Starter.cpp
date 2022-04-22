
#include "Starter.h"



int main() {
	Observer observer;
	Server socket_object;
	Player player1;
	Player player2;
	observer.set_Player1(player1);
	observer.set_Player2(player2);
	Cards cardtest;
	cardtest.setFile("Puffins.jpg");
	cardtest.setId("1");
	socket_object.set_obs(observer);
	socket_object.Start_Server();
	
	
	
	
	

	return 1;
}
