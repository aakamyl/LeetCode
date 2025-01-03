// Time: O(n + m)
// Space: O(n + m)

#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //concatenation of both strings must always yield the same result
        if ((str1 + str2) != (str2 + str1))
            return "";
        // make sure str1 is the longer string to be consistent with gcd()
        if (str1.size() < str2.size())
            swap(str1, str2); 

        // find gcd of the lengths of the two strings
        int gcdLength = gcd (str1.size(), str2.size());

        //return substring of length gcdLength
        return str1.substr(0, gcdLength);
    }
private:
    // Euclidean algorithm to find gcd
    int gcd(int num1, int num2){
        while(num2 != 0){
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
            return num1;
    }
};
