/* ------------- Approach : Using DFS ----------------- */
// Time Complexity : O(N)
// Space Complexity : O(H)


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return 0;
        }

        int remainingSum = targetSum - root->val;

        if(root->left == NULL && root->right == NULL) {
            return (remainingSum == 0);
        }

        bool leftSum = hasPathSum(root->left, remainingSum);
        bool rightSum = hasPathSum(root->right, remainingSum);

        return leftSum || rightSum;
    }
};