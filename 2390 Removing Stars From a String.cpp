// Time: O(n)
// Space: O(1)
#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int writeIndex = 0; // pointer to track write position

        // iterate the string and remove stars in-place
        for (char ch : s){
            // write a non-star character to current write position and move write pointer
            if (ch != '*'){
                s[writeIndex++] = ch;
            } else {
                writeIndex--; // for each star, move write position back to remove 1 non-star character 
            }
        }

        // return the characters written to the beginning of s
        return s.substr(0, writeIndex );
    }
};
