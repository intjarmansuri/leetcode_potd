/* ----------------- Approach : Using DFS ------------------ */
// Time Complexity : O(N)
// Space Complexity : O(H)

class Solution {
public:
    int countGoodNodes(TreeNode* node, int maxSoFar) {
        // Base case: if node is null, return 0
        if(node == NULL) {
            return 0;
        }

        // Check if current node is a good node
        int goodCountNodes = 0;
        if(node->val >= maxSoFar) {
            goodCountNodes = 1;
        }

        // Update maxSoFar with the current node's value if it's greater
        maxSoFar = max(maxSoFar, node->val);

        // Recursively count good nodes in left and right subtrees
        goodCountNodes += countGoodNodes(node->left, maxSoFar);
        goodCountNodes += countGoodNodes(node->right, maxSoFar);

        return goodCountNodes;
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        return countGoodNodes(root, root->val);
    }
};