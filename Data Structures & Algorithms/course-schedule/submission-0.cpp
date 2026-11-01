class Solution {
public:

    bool dfscycle(int node, vector<vector<int>>& adj, vector<int>& state) {
        // state: 0 = unvisited, 1 = in current DFS path, 2 = fully processed

        state[node] = 1;

        for (int neighbour : adj[node]) {
            if (state[neighbour] == 1) return true; // back edge -> cycle
            if (state[neighbour] == 0 && dfscycle(neighbour, adj, state))
                return true;
        }

        state[node] = 2;     // done, safe
        return false;
    
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        //prerequisites[i] = [a,b] -> take b to then take a 

        //so basically 1st condition is it cant go both ways 
        //second condition is [2,0] [0,1] [1,2] -> 2 - 1 - 0  so you need 2 to take 0 but you need 0 to take 2 so impossible.. graph goes 0-2 and 2-1-0 but then it became 0 -2 to cycle
        //so basically we dont want cycle also

        //therefore this is CYCLE DETECTION

        //DFS APPROACH

        //1. Make the graph.. [a,b] means b->a
        //make adj list
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto prereq_pair: prerequisites){
            adj[prereq_pair[1]].push_back(prereq_pair[0]);
        }
        //[2,0] [0,1] [1,2] [3,2] [3,1] [4,1]
        //0->2,  1->0,3,  2->1,3 , 3->null , 4->1 cycle

        //[2,0] [1,2] [3,2] [3,1] [4,1]
        //0->2,  1->3,  2->1,3 , 3->null , 4->1  NO cycle


        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && dfscycle(i, adj, state))
                return false;
        }
        return true;
        
            }
};
