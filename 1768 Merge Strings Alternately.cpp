// Time: O(n + m)
// Space: O(n + m)

#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string mergedWord; // result from merging word1 and word2
        mergedWord.reserve(n + m); //reserve space for characters in both input words

        // merge the word1 and word2 alternatively
        for(int i = 0; i < n || i < m; i++){

            // append character at current index from word1
            if (i < n) mergedWord += word1[i]; 

            // append character at current index from word2
            if (i < m) mergedWord += word2[i]; 
        }

        // return result of merging word1 and word2
        return mergedWord; 
    }
};
