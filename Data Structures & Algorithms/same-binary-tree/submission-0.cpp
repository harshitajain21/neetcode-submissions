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

        stack <TreeNode*> sp;
        stack <TreeNode*> sq;

        if(p==nullptr && q==nullptr){
            return true;
        }

        if((p==nullptr && q!=nullptr) || (p!=nullptr && q==nullptr)){
            return false;
        }

        sp.push(p);
        sq.push(q);

        while(!sp.empty() && !sq.empty()){

            TreeNode* nodep = sp.top();
            TreeNode* nodeq = sq.top();

            sp.pop();
            sq.pop();

            if(nodep->val!=nodeq->val){ //check if nodes have same values
                return false;
            }

            //check if both p and q's children at same position
            if ((nodep->left == nullptr) != (nodeq->left == nullptr)){
                return false;}
            if ((nodep->right == nullptr) != (nodeq->right == nullptr))
                return false;
            

            if(nodep->left!=nullptr){
                sp.push(nodep->left);
            }

            if(nodeq->left!=nullptr){
                sq.push(nodeq->left);
            }
            if(nodep->right!=nullptr){
                sp.push(nodep->right);
            }
            if(nodeq->right!=nullptr){
                sq.push(nodeq->right);
            }
        }
        return true;
    }
};
