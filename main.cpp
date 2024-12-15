#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
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
		holiday.readMap(map_file);
		cout << "This should be the map ...." << endl;
		holiday.printMap();
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
		cout << "2: view map\n";
		
		cin >> choice;
		switch (choice) {
			case 0: 
				holiday.saveMap(map_file);
				return 0; 
				break;
			case 1:
				terrain = holiday.movePlayer();
				holiday.describeLoc(terrain);
				break;
			case 2:
				holiday.printMap();
				break;
			default:
				cout << "Hopefully, we'll never get here\n";
				
		} // switch
		
	
	
	} while(choice != 0);   // until asked to quit, run the main program
	
	
	
	
	
	
	holiday.printMap();
	cout << "Player is on terrain type: " << terrain << endl;

	return 0;
}