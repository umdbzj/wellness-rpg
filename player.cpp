// player information
// a work in progress ... what do I want to track will change .... weekly?

#include <string>
#include <new>
#include <iostream>
#include "player.hpp"

using namespace std;


	Player::Player() {
	
	}
		
	Player::Player(string login){
		if (login == "")
			throw "Login cannot be left blank";
			
	}
		
	void Player::display(){
		
	}
		
	// is there ever a time when it would fail, other than bad input?
	bool Player::heal(int points) {
		if (points <= 0) {
			cout << "Healing is not done with negative values.  Use 'damage' instead" << endl;
			return false;
		}
		
		hp = hp + points;
		return true;
	}
		
	
	bool Player::damage(int points) {
		if (points <= 0) {
			cout << "Damage is not done with negative values.  Use 'heal' instead" << endl;
			return false;
		}	
		
		hp = hp - points;
		return true;
	}

	bool Player::addExp(int points) {
		if (points <= 0) {
			cout << "Can't have negative experience points! " << endl;
			return false;
		}
		experience = experience + points;
		return true;
	}
