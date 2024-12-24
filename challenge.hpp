#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <string>

using namespace std;

class Challenge {
	
	private:
		string task;
		int terrain;
		bool required;
		bool done;
		Challenge * next;
	
	public:
		// default constructor so that we can create collections of them unless using a linked list
		Challenge();
		
		Challenge(string todo, int terrain, bool must_complete);
		
		~Challenge();
		
		void debugMessage();
		
		void show();
		
		bool isDone();
		
		void changeStatus(bool status);
		
		int getTerrain();
		
		
} ;

#endif