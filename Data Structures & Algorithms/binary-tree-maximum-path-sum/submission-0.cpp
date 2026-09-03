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

// for each node, what can be the max if we only go down
//max sum for each node= node->val + max(left contribution, right contribution)
    
    int dfs(TreeNode* root, int& res) {
        if (!root) { 
            return 0;
        }

        int leftMax = max(dfs(root->left, res), 0);
        int rightMax = max(dfs(root->right, res), 0);
        int nodeMax= root->val + leftMax + rightMax;

        res = max(res, nodeMax );

        return root->val + max(leftMax, rightMax); //dfs(root) returns maximum path sum starting at root and going downward through ONE branch.
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }

};