// T: O(n + m)
// S: O(n + m)
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()); //populate set1 from nums1
        unordered_set<int> set2(nums2.begin(), nums2.end());//populate set2 from nums2
        vector<vector<int>> answer;
        answer.reserve(2);

        // make a list of distinct elements of nums1
        vector<int> distinctNums;
        for (int num : set1){
            if (set2.count(num) == 0){
                distinctNums.push_back(num);
            }
        } 
        // push dinstict list of nums1 to answer and clear the list
        answer.push_back(distinctNums);
        distinctNums.clear();

        // make a list of distinct elements of nums2
        for (int num : set2){
            if (set1.count(num) == 0){
                distinctNums.push_back(num);
            }
        } 
        // push dinstict list of nums2 to answer
        answer.push_back(distinctNums);

        //return final list of distinct integers in both arrays
        return answer;
    }
};
