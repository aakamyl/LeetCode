// T: O(n + m)
// S: O(1)
class Solution {
public:
    bool closeStrings(string word1, string word2) {

        // words are not close if lengths are different
        if (word1.size() != word2.size()){
            return false;
        }

        //construct a character map for word1
        unordered_map<char, int> charFreq1, charFreq2;
        for (const char& ch : word1){
            charFreq1[ch]++;
        }
        
        //construct a character map for word2 and check if characters mismatch
        for (const char& ch : word2){
            if (charFreq1[ch] < 1){ // if character is distinct
                return false;
            }
            charFreq2[ch]++;
        }

        //construct a frequency map of the character frequencies in word1
        unordered_map<int, int> freqFreq1;
        for (const auto& pair : charFreq1){
            freqFreq1[pair.second]++;
        }

        // check if character frequencies match and have same occurrences in word1 and word2 
        for (const auto& pair : charFreq2){
            // if a character frequency exists, decrement its frequency by 1 otherwise return false
            if (freqFreq1[pair.second]-- == 0){ 
                return false;
            }
        }

        // the words are close with same characters and character frequencies
        return true;
    }
};
