/* ------------- Approach : Using DFS ----------------- */
// Time Complexity : O(N)
// Space Complexity : O(H)


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        }

        if(!root->left && !root->right && targetSum == root->val) {
            return true;
        }

        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};

/* ------------- Approach : Using BFS ----------------- */
// Time Complexity : O(N)
// Space Complexity : O(H)

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        }

        // Queue to store pairs of (node, current path sum)
        queue<pair<TreeNode*, int>> que;
        que.push({root, root->val});

        while(!que.empty()) {
            auto curr = que.front();
            que.pop();

            TreeNode* node = curr.first;
            int currSum = curr.second;

            // Check if it's a leaf node and the current path sum matches the targetSum
            if(!node->left && !node->right && currSum == targetSum) {
                return true;
            }

            // Push the left child to the queue with updated path sum
            if(node->left) {
                que.push({node->left, currSum + node->left->val});
            }

            // Push the right child to the queue with updated path sum
            if(node->right) {
                que.push({node->right, currSum + node->right->val});
            }
        }

        // No path found
        return false;
    }
};