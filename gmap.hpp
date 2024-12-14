#ifndef GMAP_H
#define GMAP_H

#include <string>

#define SIZE 35

using namespace std;

class Gmap {

	private:
		int board[SIZE][SIZE];
		int px;
		int py;
	
	public:
		Gmap();
		
		int generateMap();
		
		void printMap();
		
		void saveMap(string outputfile);

};

#endif