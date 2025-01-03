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
    ListNode* oddEvenList(ListNode* head) {

        // edge case: less than 3 nodes
        if (!head || !head->next || !head->next->next){
            return head;
        }

        
        ListNode* odd = head;  // point odd to 1st node in the list
        ListNode* even = head->next; // point even to 2nd node in the list
        ListNode* evenHead = even; // preserve the first even node

        // link odd nodes and even nodes separately in-place
        while (even && even->next){

            // join the odd to the next odd node and move odd pointer forward
            odd->next = even->next;
            odd = odd->next;

            // join the even to the next even node and move even pointer forward
            even->next = odd->next;
            even = even->next;
        }
        // join odd and even nodes lists
        odd->next = evenHead;

        //return reordered list
        return head;
        
    }
};
