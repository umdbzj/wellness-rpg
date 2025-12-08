// player information
// a work in progress ... what do I want to track will change .... weekly?

#include <string>
#include <new>
#include <iostream>
#include <fstream>
#include "player.hpp"

using namespace std;


	Player::Player() {
		username = "unknown";
		player_name = "Mysterious Stranger";
		hp = 10;
		experience = 0;
	
	}
		
	Player::Player(string login){
		
		if (login == "")
			throw "Login cannot be left blank";
		
		username = login;
		player_name = "Mysterious Stranger";
		hp = 10;
		experience = 0;
		
		// if the user has a file, read that and use it
		string userfile = username + ".txt";
		ifstream input;
		ofstream output;
		input.open(userfile);
		if (!(input.fail())) { // read info from the file 
			input >> player_name;
			input >> hp;
			input >> experience;
		} else { // create a player from console input and save the new player file
			cout << "Welcome! What should we call you?" << endl;
			cin >> player_name;
			cout << "How many hit points do you have? " << endl;
			cin >> hp;
			cout << "How many experience points do you have?" << endl;
			cin >> experience;
			output.open(userfile);
			if (output.fail()) {
				cerr << "Could not create output file" << userfile << endl;
			} else {
				output << player_name << endl;
				output << hp << endl;
				output << experience << endl;
			}
			
		}
		
		if (input)
			input.close();
		if (output)
			output.close();
			
	}
		
	void Player::display(){
		cout << player_name << "'s stats:" << endl;
		cout << "Current hit points: " << hp << endl;
		cout << "Current experience points: " << experience << endl;
		
	}
		
	// is there ever a time when it would fail, other than bad input?
	bool Player::heal(int points) {
		if (points <= 0) {
			cout << "Healing is not done with negative values.  Select 'damage' instead" << endl;
			return false;
		}
		
		hp = hp + points;
		return true;
	}
		
	
	bool Player::damage(int points) {
		if (points <= 0) {
			cout << "Damage is not done with negative values.  Select 'heal' instead" << endl;
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
