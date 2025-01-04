# Time: O(n)
# Space: O(n)
from collections import deque

class RecentCounter(object):

    def __init__(self):
        # initialize a queue to store recent ping timestamps
       self.recentRequests = deque() 

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        # append current ping timestamp
        self.recentRequests.append(t)

        # remove invalid ping timestamps older than t - 3000
        while self.recentRequests[0] < (t - 3000):
            self.recentRequests.popleft()
        
        # return the number of valid ping timestamps in the queue
        return len(self.recentRequests)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
