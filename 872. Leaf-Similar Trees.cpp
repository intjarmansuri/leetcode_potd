/* --------------- Approach : Using DFS (Depth First Search) ------------- */
// Time Complexity : O(N1 + N2)
// Space Complexity : O(H1 + H2)

class Solution {
public:
    void getLeafSequence(TreeNode* root, vector<int>& leaves) {
        // Base case: If the node is null, return
        if(root == NULL) return;

        // Check if the node is a leaf node (no left and right children)
        if(root->left == NULL && root->right == NULL) {
            leaves.push_back(root->val);
            return;
        }

        if(root->left) getLeafSequence(root->left, leaves);
        if(root->right) getLeafSequence(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;

        getLeafSequence(root1, leaves1);
        getLeafSequence(root2, leaves2);

        return leaves1 == leaves2;
    }
};