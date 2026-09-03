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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int i, int left, int right ){

        if (left > right) //1. base case: when nothing left in inorder
            return nullptr;

        TreeNode* node = new TreeNode(preorder[i]); //2. create new node
 
        //3. search for that value in inorder
        int mid = left; 
        while (inorder[mid] != preorder[i])
            mid++;

        node->left = build(preorder, inorder, i+1, left, mid-1);
        node->right = build(preorder, inorder, i + (mid - left) + 1, mid+1, right);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(preorder, inorder, 0, 0, inorder.size()-1);
        
    }
};
