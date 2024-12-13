#ifndef GMAP_H
#define GMAP_H

#define SIZE 35

using namespace std;

class Gmap {

	private:
		int board[SIZE][SIZE];
		int px;
		int py;
	
	public:
		Gmap();
		
		void generateMap();
		
		void printMap();

};

#endif