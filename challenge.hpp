#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <string>

using namespace std;

class Challenge {
	
	private:
		string descrip;
		int terrain;
		bool done;
	
	public:
		// default constructor so that we can create collections of them unless using a linked list
		Challenge();
		
		Challenge(string descript, int terrain, bool status);
		
		~Challenge();
		
		void debugMessage();
		
		void show();
		
		bool isDone();
		
		void changeStatus(bool status);
		
		
} ;

#endif