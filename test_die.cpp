#include <iostream>
#include <cstdlib>
#include "die.hpp"


using namespace std;

int main() {

	srand(time(0));

	Die * ad = new Die(10);
	Die * dd = new Die(6);
	
	int result = ad->roll();
	cout << "Action die result: \n";
	switch(result) {
		case(0):
			cout << "Critical failure\n";
			break;
		case(1):
		case(2):
		case(3):
		case(4):
			cout << "You rolled: " << result << endl;
			break;
		case(5):
		case(6):
		case(7):
		case(8):
			cout << "You succeeded!\n";
			break;
		case(9):
			cout << "You have a critical success!\n";
			break;
		default:
			cout << "The gods must hate you\n";
	}
	
	result = dd->roll();
	cout << "Defense die result: \n";
	switch(result) {
		case(0):
		case(1):
		case(2):
			cout << "Shield: Action blocked\n";
			break;
		case(3):
			cout << "Pericle torch: +1 point of armor protection\n";
			break;
		case(4):
			cout << "Empty torch: change of success reduced by AD-1\n";
			break;
		case(5):
			cout << "Blank ... no benefit\n ";
		default:
			cout << "The gods must hate you\n";
	}


	return 0;
}
