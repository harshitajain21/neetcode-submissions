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
    int height(TreeNode* root){ //height(node) = 1 + max(height(left), height(right))

        if (root == nullptr) 
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return 1 + max(leftHeight, rightHeight);
}
    bool isBalanced(TreeNode* root) {

        //check node->left's height and node->right's height 
        if(root==nullptr){
            return true;
        }

        stack <TreeNode* > st;

        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if (abs(height(node->left) - height(node->right))>1){
                return false;
            }

            if(node->left!=nullptr){
                st.push(node->left);
            }

            if(node->right!=nullptr){
                st.push(node->right);
            }
        }

        return true;
    }
};
