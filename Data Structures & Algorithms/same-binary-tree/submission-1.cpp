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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q){
            return true;
        }

        if (p && q && p->val == q->val) { //node is equal so now check subtree
                bool leftsubtree = isSameTree(p->left, q->left);
                bool rightsubtree = isSameTree(p-> right, q-> right);
            return (leftsubtree && rightsubtree);
        } else {
            return false;
        }
        
    }
};
