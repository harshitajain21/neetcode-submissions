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

    pair<bool, int> dfs(TreeNode* root) {

        // base case
        if (root == nullptr)
            return {true, 0};

        // Leap of faith:
        // Assume these correctly give us the answer
        // for the left and right subtrees.
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);

        // Check if current tree is balanced
        bool balanced = (left.first & right.first) && // both left and right subtree balanced
                        (abs(left.second - right.second) <= 1); //height diff < 1

        // Height of current tree
        int height = 1 + max(left.second, right.second);

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
