// Time: O(n)
// Space: O(n)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        // get the maximum candies a kid has
        int maxCandies = *max_element(candies.begin(), candies.end());

        // for each kid: check if he can have maximum candies and save result
        vector<bool> results;
        for (const int& kidCandies : candies){
            results.push_back((kidCandies + extraCandies) >= maxCandies);
        }

        // return results of all the checks
        return results;
    }
};
