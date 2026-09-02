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
        //do bfs and write the last element in each level
        vector<int> result;

        queue <TreeNode*> q;

        if(!root)
            return result;
        
        q.push(root);

        while(!q.empty()){
            vector<int> level;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                int x=node->val;
                q.pop();
                level.push_back(x);

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            }
            result.push_back(level.back());

        }
        return result;
    }
};
