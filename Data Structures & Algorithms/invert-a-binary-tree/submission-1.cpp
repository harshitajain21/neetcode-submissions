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
    TreeNode* invertTree(TreeNode* root) {

        /*Put the root into the stack.
While the stack isn't empty:
- Pop a node.
- If it has no children, do nothing.
- Otherwise, swap its left and right children.
- Push its children into the stack.*/

if(root==NULL){
    return root;
}

//1. put root in stack
stack <TreeNode*> st;
st.push(root);

while(!st.empty()){
    TreeNode* node=st.top();
    st.pop();
    swap(node->left,node->right);

    if(node->left!=NULL){
        st.push(node->left);
    }
    if(node->right!=NULL){
        st.push(node->right);
    }
}

 return root;             
    }
};
