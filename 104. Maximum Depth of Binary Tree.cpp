/* --------------- Approach : Using DFS (Depth First Search) ------------- */
// Time Complexity : O(N)
// Space Complexity : O(H)


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};