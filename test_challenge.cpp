/*  tester for the challenge class */

#include <iostream> 
#include <vector>
#include <cstdlib>
#include <ctime>
#include "challenge.hpp"

using namespace std;

int main() {

	srand(time(0));

	// create several challenges
	Challenge c1("Find a tree and do pullups on a branch", 1, false);
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
	
	
	// print all for testing
	for (int i = 0; i < challenges.size(); i++) {
		challenges[i].debugMessage();
		cout << endl;
	
	}
	
	
	// pick one at random
	int oracle = rand() % challenges.size();
	cout << "Today's challenge: " << endl;
	challenges[oracle].show();
	
	
	// change its status to done
	challenges[oracle].changeStatus(true);
	
	
	cout << "\nPrint undone challenges\n";
	// print all undone challenges
	for (int i = 0; i < challenges.size(); i++) {
		if (!challenges[i].isDone()) {
			challenges[i].show();
			cout << endl;
		}
	
	}
	



	return 0;
}

