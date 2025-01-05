// T: O(n)
// S: O(1)
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefixSum = 0, totalSum = 0;
        int size = nums.size();

        //calculate total sum of elements
        for (int num : nums){
            totalSum += num;
        }

        // calculate prefix sums and compare to sufix sums
        for (int i = 0; i < size; i++){
            if (prefixSum == (totalSum - prefixSum - nums[i])){
                return i; // return leftmost index where there is a match
            }
            prefixSum += nums[i]; // update prefix sum for index i + 1
        } 

        return -1; // there is no pivot index
    }
};
