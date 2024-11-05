/* ------------- Approach : Using Three Pointer (Prev, Curr, Next) ------------*/
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};