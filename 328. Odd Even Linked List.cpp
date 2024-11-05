/* ---------- Approach : Two Pointer (one to handle odd-indexed nodes (odd) and another to handle even-indexed nodes (even)) ------------ */
// Time Complexity : O(N)
// Space Complexity : O(1)


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // Store the starting point of the even list.

        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        // Connect the end of the odd list to the head of the even list.
        odd->next = evenHead;
        return head;
    }
};