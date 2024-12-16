
#include <iostream>
#include <string>
#include "challenge.hpp"

using namespace std;

		Challenge::Challenge(){
			descrip = "A blank piece of parchment falls from the sky into your hands. What could it mean?\n";
			terrain = 0;
			done = false;
		
		}
		
		Challenge::Challenge(string descript, int terrain, bool status) {
			descrip = descript;
			this->terrain = terrain;
			done = status;
		}
		
		Challenge::~Challenge(){
			// cout << "Well, that was easy!\n";
		}
		
		void Challenge::debugMessage(){
			cout << "Challenge: " << descrip << " for terrain type: " << terrain << " is ";
			if (!done) {
				cout << "not ";
			}
			cout << "done\n";
		}
		
		void Challenge::show() {
			cout << descrip << endl;
		}
		
		bool Challenge::isDone() {
			return done;
		}
		
		void Challenge::changeStatus(bool status){
			done = status;
		
		}