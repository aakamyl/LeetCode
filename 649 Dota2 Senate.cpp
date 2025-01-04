// Time: O(n)
// Space: O(n)
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> direQueue, radiantQueue;
        int n = senate.size();

        // push the positions of senators in senate to their respective queues
        for (int i = 0; i < n; i++){
            if (senate[i] == 'R'){
                radiantQueue.push(i);
            } else { 
                direQueue.push(i);
            }
        }

        // start voting and until a winner emerges
        while (!direQueue.empty() && !radiantQueue.empty()){

            // take the front senator from both queues 
            int radiant = radiantQueue.front();
            int dire = direQueue.front();
            radiantQueue.pop();
            direQueue.pop();

            // the earlier senator bans the other senator and rejoins his queue with a lower priority than all senators yet to vote in the current round
            if (radiant < dire){
                radiantQueue.push(radiant + n);
            } else {
                direQueue.push(dire + n); 
            }
        }
        // the queue that survives has the victory
        return direQueue.empty() ? "Radiant" : "Dire";
    }
};
