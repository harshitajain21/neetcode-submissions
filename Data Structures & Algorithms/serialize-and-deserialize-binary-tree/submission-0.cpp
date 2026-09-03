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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        //so we have to understand what each node represents
        /*
        1-2,3-n,n,4,5

        but we don't need - to represent levels bcz we already have n to rep null so we can just write 1,2,3,n,n,4,5
        */

        queue <TreeNode*> q;

        string s ="";

        if(!root){
            return s;
        }

        q.push(root);

        while(!q.empty()){

            if(!q.front()){
                s+="n";
                s+=",";
                q.pop();
            }
            else{
            TreeNode* node = q.front();
            q.pop();

            s+=to_string(node->val);
            s+=",";
            
            q.push(node->left);
            q.push(node-> right);}

            
        }

        return s;
              
    }

    // Decodes your encoded data to tree.


    TreeNode* deserialize(string data) {

        /*1. i=0 : make new node put 1
        2. i=1 : , 
        3. i=2 : 2 : node->left =2
        4. ,
        5. 3 : node->right = 3.. now node-> right is processed so node = node-> left
        6. ,
        7. n : node->left = n*/
    if (data.empty()) return nullptr;
    
    vector<string> tokens;
    stringstream ss(data);
    string token;
    while (getline(ss, token, ',')) {
        if (!token.empty()) tokens.push_back(token);
    }
    
    if (tokens.empty() || tokens[0] == "n") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < tokens.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        // Left child
        if (i < tokens.size()) {
            if (tokens[i] != "n") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;
        }
        
        // Right child
        if (i < tokens.size()) {
            if (tokens[i] != "n") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }}
    
    
    return root;}
};
