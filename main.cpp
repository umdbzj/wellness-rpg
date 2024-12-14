#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "gmap.hpp"

using namespace std;

int main() {

	srand(time(0));

	char status = 'n';
	int choice = 0;
	Gmap holiday;
	string map_file = "map.txt";
	ifstream map_in;
	ofstream save_map;
	int terrain = 0;
	
	// start game
	cout << "\nWelcome to the Wellness RPG!\n";
	
	cout << "Starting options\n";
	cout << "1: Start a new game\n";
	cout << "2: Load an existing game\n";
	cout << "0: Quit\n";
	cin >> choice;       // need to handle possible error here

	if (choice == 1) {
		cout << "Creating a new map\n";
		terrain = holiday.generateMap();
	} else if (choice == 2){
		// try to open the map file and handle errors appropriately
		cout << "Let's see the map ....\n";
	} else {
		cout << "Exiting\n";
		return 0;
	}

	// main game menu
	// file streams created outside of the switch statement so that they can be used
	choice = 0;
	do {
		cout << "What do you want to do?\n";
		cout << "0: save and quit\n";
		cout << "1: move player\n";
		
		cin >> choice;
		switch (choice) {
			case 0: 
				save_map.open(map_file);
				if (save_map) {
					for (int i = 0; i < SIZE; i++) {
						for (int j = 0; j < SIZE; j++) {
							save_map << 0 << " ";
						}
						
						save_map << endl;
					}
				} // if we opened the file
				break;
			case 1:
				cout << "Will need to move the player\n";
				break;
			default:
				cout << "Hopefully, we'll never get here\n";
				
		} // switch
		
	
	
	} while(choice != 0);   // until asked to quit, run the main program
	
	
	
	
	
	
	holiday.printMap();
	cout << "Player is on terrain type: " << terrain << endl;

	return 0;
}