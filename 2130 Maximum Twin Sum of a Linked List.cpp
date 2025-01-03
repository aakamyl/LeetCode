// Time: O(n)
// Space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <algorithm>

using namespace std;

class Solution {
public:
    int pairSum(ListNode* head) {
        
        // find the middle node of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // determine the maximum pair sum
        int pairSum = 0;
        int maxPairSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while(secondHalf){

            // calculate the sum of a pair and compare with maximum pair sum 
            pairSum = firstHalf->val + secondHalf->val;
            maxPairSum = max(maxPairSum, pairSum);

            // move to next twin nodes
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
            
        }

        // return maximum pair sum in the list
        return maxPairSum;
    }
};
