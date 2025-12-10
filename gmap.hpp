#ifndef GMAP_H
#define GMAP_H

#include <string>
#include <vector>

#define SIZE 35
#define NUM_TERRAIN 9

using namespace std;

class Gmap {

	private:
		int board[SIZE][SIZE];
		int px;
		int py;
		
		string terrains[NUM_TERRAIN];
	
	public:
		Gmap();
		
		~Gmap();
		
		int generateMap();
		
		void printMap();
		
		void saveMap(string outputfile);
		
		void readMap(string inputfile);
		
		int movePlayer();
		
		void teleportPlayer();
		
		void describeLoc(int terrain);
		
		string getPlayerTerrain();

};

#endif