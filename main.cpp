#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include "gmap.hpp"
#include "challenge.hpp"

using namespace std;

int addChallenge(int terrain) {

	// create several challenges
	Challenge c1("Practice pullups", 1, false);
	Challenge c2("Do Sudoku on the Brain Age app", 2, false);
	Challenge c3("Push your max speed up to 4.4 mph", 3, false);
	Challenge c4("Find a way to access a pool", 4, false);
	Challenge c5("Review recurring expenses and cancel one", 5, false);
	Challenge c6("Journal exercises", 6, false);
	Challenge c7("Review first aid training materials", 7, false);
	Challenge c8("Invite someone for a walk or coffee", 8, false);
	
	// a vector of challenges or pointers to challenges
	vector<Challenge> challenges;
	challenges.push_back(c1);
	challenges.push_back(c2);
	challenges.push_back(c3);
	challenges.push_back(c4);
	challenges.push_back(c5);
	challenges.push_back(c6);
	challenges.push_back(c7);
	challenges.push_back(c8);
	
	cout << "\nToday's challenge:\n";
	int curChallenge = -1;
	// print challenge for the terrain type
	// linear search, but we'll improve this later
	for (int i = 0; i < challenges.size(); i++) {
		if (!challenges[i].isDone() && challenges[i].getTerrain() == terrain) {
			challenges[i].show();
			cout << endl;
			curChallenge = i;
		}
	
	}
	
	return curChallenge;
}


int main() {

	srand(time(0));

	// char status = 'n';
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
				addChallenge(terrain);
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