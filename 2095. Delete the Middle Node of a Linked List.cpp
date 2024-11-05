/* ------------- Approach: Use two pointers (slow and fast) ---------------- */
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // Edge case: List with one node
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        if(prev != NULL) {
            prev->next = slow->next;
        }
        return head;
    }
};