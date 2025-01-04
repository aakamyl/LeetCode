// Time: O(n)
// Space: O(n)

class Solution {
public:
    string decodeString(string s) {
        stack<string> stack;
        string current = "";
        int k = 0;

        // iterate the encoded string
        for (char c : s){
            
            // if character is a digit update k value 
            if (isdigit(c)){
                k = k * 10 + (c - '0');
            } else if ( c == '['){
                // push current substring and k value to stack and reset current and k
                stack.push(current);
                stack.push(to_string(k));
                current = "";
                k = 0;
            } else if (c == ']'){

                // pop k and current substring and decode substring
                int repeat = stoi(stack.top());
                stack.pop();
                string temp = current;
                while ( repeat > 1) {
                    current += temp;
                    repeat--;
                }

                current = stack.top() + current;
                stack.pop();

            } else {
                // add character to back of current substring
                current += c;
            }
        }

        // return decoded string
        return current;
    }
};
