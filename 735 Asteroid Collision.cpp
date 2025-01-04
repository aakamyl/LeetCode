// Time: O(n)
// Space: O(1)
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int leftPos = 0;
        int size = asteroids.size();

        for (int rightPos = leftPos + 1; rightPos < size; rightPos++){

            // there is no collision if asteroid is the first or is moving right or previous asteroid was moving left
            if (leftPos < 0 || asteroids[leftPos] < 0 || asteroids[rightPos] > 0){
                asteroids[++leftPos]  = asteroids[rightPos];

            } else { // previous and current asteroids are moving towards each other and would collide

                
                while (leftPos >= 0 && asteroids[leftPos] > 0) {
                    
				  // collision: left asteroid is larger so right asteroid explodes    
                    if (asteroids[leftPos] + asteroids[rightPos] > 0){
                        break; 

                    } else if (asteroids[leftPos] + asteroids[rightPos] == 0){
					 // collision: left and right asteroids are equal and both explode
                        leftPos--; 
                        break; 

                    } else {
					 // collision: right asteroid is larger and a left asteroid moving right explodes
                        leftPos--; 
					 
					 // all asteroids moving right explode, leaving only asteroids moving left or none
                        if (leftPos < 0 || asteroids[leftPos] < 0){
                            asteroids[++leftPos]  = asteroids[rightPos];
                        }
                    }
                }
            }
        }
	   // trim off exploded asteroids and return result
        asteroids.resize(++leftPos);
        return asteroids;  
    }
};
