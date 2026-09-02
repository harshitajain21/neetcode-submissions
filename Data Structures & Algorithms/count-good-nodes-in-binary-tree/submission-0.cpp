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
    int dfs(TreeNode* node, int maxval) {
        if (!node) {
            return 0;
        }

        int count=0;

        if(node->val>=maxval){
            maxval=node->val;
            count++;
        }
        count += dfs(node->left, maxval);
        count += dfs(node->right, maxval);
        return count;
    }

    int goodNodes(TreeNode* root) {
     //while doing dfs, mantain maxseen and check each and update count  
     //note:maxseen should be for each path

     return dfs(root, root->val);

    }
};
