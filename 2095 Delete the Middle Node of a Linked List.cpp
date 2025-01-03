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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        // return empty list if there is only 1 node
        if (!head->next){
            return nullptr;
        }

        // move slow pointer to the middle node
        while (fast && fast->next){
            fast = fast->next->next; // move fast two steps 
            prev = slow;
            slow = slow->next; // move slow 1 step
        }

        // delete middle node
        prev->next = slow->next;
        // return head of the list
        return head;
    }
};
