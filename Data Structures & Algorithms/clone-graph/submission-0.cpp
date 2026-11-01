/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, map<Node*, Node*> &oldtonew){
        if(node==NULL){
            return nullptr;
        }
        if(oldtonew.count(node)){ //if this node is already seen, return its clone
            return oldtonew[node];
        }

        //create a new node
        Node* copy =new Node(node->val);
        oldtonew[node]=copy; //store this node as clone 

        for(Node* neighbor : node->neighbors){
            copy->neighbors.push_back(dfs(neighbor, oldtonew));
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        map <Node*, Node*> oldtonew;
        return dfs(node, oldtonew);
    }
};
