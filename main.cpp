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
	
	cout << "Is this a new game? (y or n)\n";
	cin >> status;
	if (status == 'y') {
		cout << "Creating a new map\n";
		holiday.generateMap();
	} else {
		// try to open the map file and handle errors appropriately
		cout << "Let's see the map ....\n";
	}
	
	holiday.printMap();

	return 0;
}