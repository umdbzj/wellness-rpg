#include <iostream>
#include "die.hpp"

using namespace std;

		Die::Die () {
			sides = 0;
		}
		
		Die::Die(int num_sides) {
			sides = num_sides;
		}
		
		// returns the value rolled
		int Die::roll()  {
			int result = rand() % sides;
			
		return result;
			
		
		}
		