// T: O(n)
// S: O(1)
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // initialize altitude of a point and maximum altitude
        int maxAltitude = 0, currentAltitude = 0;

        //visit all the points from beginning to end
        for (const auto& g : gain){
            // calculate altitude of the current point
            currentAltitude += g;
            // track maximum altitude seen so far
            maxAltitude = max(maxAltitude, currentAltitude);
        }
        // return maximum altitude seen after all points are visited
        return maxAltitude;
    }
};
