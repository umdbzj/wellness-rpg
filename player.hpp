// player information
// a work in progress ... what do I want to track will change .... weekly?

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <new>

using namespace std;

class Player {
	private:
		string username;
		string player_name;
		int hp;
		int experience;
	
	public:
		Player();
		
		Player(string login);
		
		void display();
		
		// is there ever a time when it would fail, other than bad input?
		bool heal(int points);
		
		// 
		bool damage(int points);
		
		bool addExp(int points);

};


#endif