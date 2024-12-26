#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
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
		
		Gmap::~Gmap() {
			cout << "Mischief managed\n";
		}
		
		int Gmap::generateMap() {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					board[i][j] = rand() % 8 + 1;
				}
			}	
			
			px = rand() % 35;
			py = rand() % 35;
			
			int loc = board[px][py];		
		
			return loc;
		}
		
		void Gmap::printMap() {
			int terrain = board[px][py];
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					if (px == i && py == j) {
						cout << " P ";
					} else {
						terrain = board[i][j];
						switch (terrain) {
							case 0:
								cout << " _ ";
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
					
					} // if ... else

				}
				cout << endl;
			}	
			cout << endl;
			cout << "Player is at: (" << px << ", " << py << ")"  << endl;
			terrain = board[px][py];
			describeLoc(terrain);
			
		
		} // printing
		
		void Gmap::saveMap(string outputfile) {
		
			// open the map file for printing		
			ofstream output(outputfile);
			
		   // Check if the file opened successfully
   		   if (!output.is_open()) {
        		std::cerr << "Error saving " << outputfile << endl;
        		return;
    		}
			
			if (output.is_open()) {
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						output << board[i][j] << " ";
					}		
				output << endl;  
				}  // printed the table
				
				output << px << " " << py;  // player position
				
				output.close();
				
			}  // output opened successfully
			
		} // end method
		
		void Gmap::readMap(string inputfile)  {
			// open file for reading
			ifstream input(inputfile);
			
			// Opened successfully?
			if (!input.is_open()) {
				cerr << "Error reading " << inputfile << endl;
				return;
			} else {
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						input >> board[i][j];
					}
				}
				
				// player position
				input >> px;
				input >> py;
			
			}
		
		} // readMap
		
		int Gmap::movePlayer() {
			int direction = 0;
			cout << "Which direction do you want to move?\n";
			cout << "0: show the map\n";
			cout << "1: NW\n";
			cout << "2: N\n";
			cout << "3: NE\n";
			cout << "4: W\n";
			cout << "6: E\n";
			cout << "7: SW\n";
			cout << "8: S\n";
			cout << "9: SE\n";
			
			cin >> direction;
			
			switch (direction) {
				case 0:
					printMap();
					break;
				case 1:
					px--;
					py--;
					break;
				case 2:
					py--;
					break;
				case 3:
					px--;
					py++;
					break;
				case 4:
					px--;
					break;
				case 6:
					px++;
					break;
				case 7:
					px--;
					py++;
					break;
				case 8:
					py++;
					break;
				case 9:
					px++;
					py++;
					break;
				default:
					cerr << "Please enter a valid direction\n";
			}
			
			// make sure the player is not attempting to move off the board
			if (px < 0 || px >= 35 || py < 0 || py >= 35) {
				cout << "Player location: " << px << ", " << py << " is off the charts.\n";
				teleportPlayer();
			}			
			
			return board[px][py];   // type of terrain
		}
		
		void Gmap::teleportPlayer() {
			cout << "You suddenly feel strange ... like your body is dissolving and reforming\n";
		
			// get random x and y coordinates  for player
			int x = rand() % 35;
			int y = rand() % 35;
			px = x;
			py = y;
			
			cout << "The moment passes, but you look around and realize your surroundings have changed\n";
			cout << "Where are you??\n";
			cout << "Player new location: " << px << ", " << py << endl;
		}
		
		void Gmap::describeLoc(int terrain) {
		
			switch (terrain) {
				case 0:
					cout << "Congratulations!  You have stumbled upon a fixed teleportion circle\n";
					break;
				case 1:
					cout << "You are standing in a forest with trees extending as far as you can see.\n";
					cout << "Paths lead in all directions.  You'd better pick one and start walking ";
					cout << "before something notices you\n";
					break;
				case 2:
					cout << "Expansive grasslands surround you, inviting you to pick a direction ";
					cout << "in which to explore\n";
					break;
				case 3:
					cout << "You are at a crossroads.  Roads and paths extend in many directions\n";
					break;
				case 4:
					cout << "The water is calm enough for you to swim across.\n";
					break;
				case 5: 
					cout << "Ugh!  The area around you is swampy bog. Too wet to walk over, ";
					cout << "but not deep enough for swimming.  Thankfully, a boat is tied up nearby.\n";
					cout << "Start rowing!\n";
					break;
				case 6:
					cout << "Some mountains just need to be climbed.\n";
					break;
				case 7:
					// make the injured party random 
					cout << "You come across an injured man alongside the path.  Looks like you ";
					cout << "will need to help him to the hut you can just see in the distance.\n";
					break;
				case 8:
					cout << "You arrive at a small village. At last!  A chance to rest and restock!\n";
					break;
				default:
					cout << "You are standing in a featureless void.  How did you get here?\n";
			}
			
		}

		
		