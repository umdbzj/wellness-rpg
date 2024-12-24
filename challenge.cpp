
#include <iostream>
#include <string>
#include "challenge.hpp"

using namespace std;

		Challenge::Challenge(){
			task = "TBD";
			terrain = 0;
			required = false;
			done = false;
			next = NULL;
		
		}
		
		Challenge::Challenge(string todo, int terrain, bool must_complete) {
			task = todo;
			this->terrain = terrain;
			required = must_complete;
			done = false;
			next = NULL;
		}
		
		Challenge::~Challenge(){
			// cout << "Well, that was easy!\n";
			next = NULL;
		}
		
		void Challenge::debugMessage(){
			cout << "Challenge: " << task << " for terrain type: " << terrain;
			cout << " is ";
			if (!done) {
				cout << "not ";
			}
			cout << "done\n";
		}
		
		void Challenge::show() {
			cout << task << endl;
		}
		
		bool Challenge::isDone() {
			return done;
		}
		
		void Challenge::changeStatus(bool status){
			done = status;
		
		}
		
		int Challenge::getTerrain() {
			return terrain;
		}