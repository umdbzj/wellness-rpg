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
		
		int Gmap::generateMap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					board[i][j] = rand() % 8 + 1;
				}
			}	
			
			px = rand() % 35;
			py = rand() % 35;
			
			int loc = board[px][py];
			board[px][py] = 0;   // for now 		
		
			return loc;
		}
		
		void Gmap::printMap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					int terrain = board[i][j];
					switch (terrain) {
						case 0:
							cout << " P ";
							break;
						case 1:
							cout << " # ";
							break;
						case 2:
							cout << " \" ";
							break;
						case 3: 
							cout << " - ";
							break;
						case 4:
							cout << " ~ ";
							break;
						case 5:
							cout << " = ";
							break;
						case 6:
							cout << " ^ ";
							break;
						case 7: 
							cout << " + ";
							break;
						case 8: 
							cout << " o ";
							break;
						default:
							cout << " ? ";
					} // switch

				}
				cout << endl;
			}	
			cout << endl;
			cout << "Player is at: (" << px << ", " << py << ")"  << endl;
			
		
		} // printing