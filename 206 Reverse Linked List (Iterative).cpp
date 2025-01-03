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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // the current and previous nodes in the reversed list
        ListNode* prev = nullptr;
        ListNode* curr = head;

        // iterate the whole list and reverse it
        while (curr){
            head = head->next; // remove the head node of the list
            curr->next = prev; // reverse the current link
            prev = curr;   // current node becomes the previous node
            curr = head;    // move to next node
            
        } 
        
        // return the last visited node as the head of the reversed list
        return prev;
    }
};
