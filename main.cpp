#include <iostream>
#include <fstream>
#include <cstdlib> 
#include "gmap.hpp"

using namespace std;

int main() {

	srand(time(0));

	char status = 'n';
	Gmap holiday;
	string map_file = "map.txt";
	int terrain = 0;
	
	cout << "Is this a new game? (y or n)\n";
	cin >> status;
	if (status == 'y') {
		cout << "Creating a new map\n";
		terrain = holiday.generateMap();
	} else {
		// try to open the map file and handle errors appropriately
		cout << "Let's see the map ....\n";
	}
	
	
	holiday.printMap();
	cout << "Player is on terrain type: " << terrain << endl;

	return 0;
}