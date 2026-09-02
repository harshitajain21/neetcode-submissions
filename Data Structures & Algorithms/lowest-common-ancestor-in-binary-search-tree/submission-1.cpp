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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

   //3,7 : 5
   //4, 8 -> 5

   //basically we have to find root s.t p<=root<=q if p<q
   //so just do dfs and check each node

   int p1=p->val;
   int q1=q->val;

   int small=min(p1,q1);
   int large=max(p1,q1);

   if(small<=root->val && root->val<=large){
    return root;
   } 
   if(root->val>=large){
    return(lowestCommonAncestor(root->left, p,q));
   }
    return(lowestCommonAncestor(root->right, p,q));

    }
};
