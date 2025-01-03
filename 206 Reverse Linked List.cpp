// Time: O(n)
// Space: O(n)
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // call recursive function to reverse list
        return recurRevList(nullptr, head);
    }
private:

    // recursive function to reverse a list
    ListNode* recurRevList(ListNode* prev, ListNode* curr){

        // base case: empty list
        if (!curr){
            return prev;
        } else {

            // reverse links recursively
            ListNode* nextNode = curr->next;
            curr->next = prev;
            return recurRevList(curr, nextNode);
        }
        
    }
};
