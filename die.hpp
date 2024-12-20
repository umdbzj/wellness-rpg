#ifndef DIE_H
#define DIE_H


class Die {

	private:
		int sides;
	
	public:
		Die ();
		
		Die(int num_sides);
		
		// returns the value rolled
		int roll();


};

#endif