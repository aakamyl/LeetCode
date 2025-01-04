// Time: O(n)
// Space: O(n)

#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        // set the queue to empty
        recentRequests = {}; 
    }
    
    int ping(int t) {
        // push current timestamp to queue and determine the oldest valid timestamp
        recentRequests.push(t);
        int oldest = t - 3000;

        // remove any timestamp older than the oldest valid timestamp
        while (!recentRequests.empty() && recentRequests.front() < oldest){
            recentRequests.pop();
        }

        // return number of valid timestamps in the queue
        return recentRequests.size();
    }

private:
    // a queue data structure to store recent pings
    queue<int> recentRequests;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
