// Approach 1 : Using BFS(level order traversal)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) {
            return {};
        }

        vector<int> result;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            TreeNode* temp = NULL;

            while(n--) {
                temp = que.front();
                que.pop();

                if(temp->left) {
                    que.push(temp->left);
                }

                if(temp->right) {
                    que.push(temp->right);
                }
            }
            result.push_back(temp->val);
        }
        return result;
    }
};

// Approach - 2 : Using DFS(preOrder traversal)

class Solution {
public:

    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if(root == NULL) {
            return;
        }

        if(result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, level+1, result);
        preOrder(root->left, level+1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        preOrder(root, 1, result);
        return result;
    }
};