// T: O(n)
// S: O(1)
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // initialize counters and back pointer
        int maxLength = 0, zeroCount = 0, back = 0;

        // iterate the binary array with forward pointer
        for (int forward = 0; forward < nums.size(); forward++){
            // count the number of zeroes seen
            if (nums[forward] == 0){
                zeroCount++;
            }

            // slide the back point forward if more than one zero is seen 
            while (zeroCount > 1){
                // decrement zeroCount if a zero is seen
                if (nums[back] == 0){
                    zeroCount--;
                } 
                back++; // slide out element
            }

            // calculate the maximum seen so far after deleting one element
            maxLength = max(maxLength, forward - back);

        }
        // return maximum count of one's after deleting one element
        return maxLength;  
    }
};
