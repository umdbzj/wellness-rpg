#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "gmap.hpp"

using namespace std;

		Gmap::Gmap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					board[i][j] = 0;
				}
			}
			
			px = 0;
			py = 0; 
			
		} // constructor
		
		void Gmap::generateMap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					board[i][j] = rand() % 7 + 1;
				}
			}	
			
			px = rand() % 35;
			py = rand() % 35;
			
			board[px][py] = 0;   // for now 		
		
		
		}
		
		void Gmap::printMap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					cout << board[i][j] << " " ;
				}
				cout << endl;
			}	
			cout << endl;
			cout << "Player is at: (" << px << ", " << py << ")"  << endl;
			
		
		} // printing