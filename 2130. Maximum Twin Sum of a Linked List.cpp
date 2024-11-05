/* ---------- Approach : (Find the Middle of the Linked List, Reverse the Second Half, Calculate Twin Sums) -------------- */
// Time Complexity: O(N)
// Space Complexity : O(1)


class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find the middle of the LL
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the LL
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Calculate twin sums and find the maximum
        int maxSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;
        while(secondHalf) {
            maxSum = max(maxSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return maxSum;
    }
};
