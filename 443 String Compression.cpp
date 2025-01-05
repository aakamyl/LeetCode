// T: O(n)
// S: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        // iterate chars, count consecutive repeating characters and modify chars in-place
        int i = 0, chCount = 0;
        for(auto ch : chars){
            if(ch == chars[i]){
                chCount++; // count consecutive repeating characters
            } else {
                // distinct character encounted, compress previous character
                if(chCount > 1){
                    for(auto d : to_string(chCount)){
                        chars[++i] = d;
                    }
                }
                // begin counting current character
                chars[++i] = ch;
                chCount = 1;
            }
        } 
        // compress the last distinct character 
        if(chCount > 1){
            for(auto d : to_string(chCount)){
                chars[++i] = d;
            }
        }
        
        // return length of compressed chars array
        return ++i; 
    }
};
