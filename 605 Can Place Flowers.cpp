// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        //edge case: n = 0
        if (!n){
            return true;
        }
         // edge case: size of flowerbed is 1
        if (size == 1) {
            return flowerbed[0] == 0 && n <= 1;
        }

        // check if new flowers can be planted in the flowerbed
        for (int i = 0; i < size; i++) {
            // check if the current plot and its neighbors are empty
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                
                flowerbed[i] = 1; // place a flower
                n--; // decrease flowers left to be planted
                if (n == 0) return true; // all the new flowers are planted
                
            }

        }
        return false; // some new flowers could not be planted
    }
};
