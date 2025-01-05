// T: O(n)
// S: O(n)

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freqs; // map of frequencies of elements
        unordered_set<int> seenFreqs; // set to keep track of seen frequencies

        //build the frequencies
        for (int num : arr){
            freqs[num]++;
        }

        //check for frequency collision
        for (auto pair : freqs){
            //check if insertion failed due to frequency collision
            if (!seenFreqs.insert(pair.second).second){
                return false;
            } 
        }  

        return true; // no collision, the frequencies are unique 
    }
};
