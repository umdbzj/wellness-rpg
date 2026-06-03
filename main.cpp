#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <ctime>
#include "gmap.hpp"
#include "challenge.hpp"
#include "player.hpp"

using namespace std;

// might move ... but to what class?
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

	srand(time(0));               // set up the RNG
	
	// send errors to a log file
	ofstream errorFile("error_log.txt");
	if (!errorFile.is_open()) {
		cerr << "Failed to open error log for saving errors" << endl;
		cerr << "(Yes, extra points for the irony of this message ...)" << endl;
		exit(1);	
	}
	cerr.rdbuf(errorFile.rdbuf());
	cerr << "Check that this went to a file." << endl;

	// char status = 'n';
	int choice = 0;
	Gmap holiday;
	string map_file = "map.txt";
	ifstream map_in;
	ofstream save_map;
	int terrain = 0;
	
	string user = "";
	
	// start game
	cout << "\nWelcome to the Wellness RPG!\n";
	time_t now = time(0);
	cout << "Date is: " << ctime(&now) << endl;
	
	
	// create a log file for today?
	// using public data fields in the tm struct
	tm* local_t = localtime(&now);
	string logfile = "logs/" + to_string((local_t->tm_year + 1900));
	logfile = logfile + to_string((local_t->tm_mon + 1));
	logfile = logfile + to_string(local_t->tm_mday) + ".log";
	cout << "Today's log file saved in: " << logfile << endl; 
	ofstream todays_log;
	todays_log.open(logfile);
	
	if (todays_log.fail()) {
		cerr << "Could not open the log file: " << logfile << endl;
		exit(1);
	}
	
	
	cout << "What is your user login? " << endl;
	cin >> user;
	
	// create the player from their file or create a new player
	cout << endl;
	Player player1(user);
	
	player1.display();
	
	
	cout << "\nStarting options\n";
	cout << "1: Start a new game\n";
	cout << "2: Load an existing game\n";
	cout << "0: Quit\n";
	cin >> choice;       // need to handle possible error here

	if (choice == 1) {
		// create a new player 

		cout << "Creating a new map\n";
		terrain = holiday.generateMap();
	} else if (choice == 2){
		// for now, ask for user name and load the player
		// echo stats to the screen
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
		cout << "3: show player information\n";
		
		cin >> choice;
		switch (choice) {
			case 0: 
				holiday.saveMap(map_file);
				// save player info
				// return 0; 
				break;
			case 1:
				terrain = holiday.movePlayer();
				holiday.describeLoc(terrain);
				addChallenge(terrain);
				break;
			case 2:
				cout << "The map so far...." << endl;
				holiday.printMap();
				break;
			case 3: 
				cout << endl;
				player1.display();
				cout << endl;
				break;
			default:
				cout << "Hopefully, we'll never get here\n";
				
		} // switch
		
	
	
	} while(choice != 0);   // until asked to quit, run the main program
	
	cout << "Current map:" << endl;
	holiday.printMap();
	cout << "Player is on terrain type: " << holiday.getPlayerTerrain() << endl;

	if (errorFile.is_open())
		errorFile.close(); 
		
	if (todays_log.is_open())
		todays_log.close();
	return 0;
}