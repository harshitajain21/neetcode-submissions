class Solution {
public:

//1. connected component count =1
//2. no cycles

    void dfs(vector<vector<int>> &adj, vector<int> &visited, int node ){        
        visited[node]=true;

        for (int neighbour : adj[node]) { 
            if (!visited[neighbour]) {
                dfs(adj, visited, neighbour);
        }
    }
    }

    bool cycle_dfs(vector<vector<int>>& adj, vector<int>& visited,
         int node, int parent) {

    visited[node] = 1;

    for (int neighbour : adj[node]) {

        if (!visited[neighbour]) {
            if (cycle_dfs(adj, visited, neighbour, node)) {
                return true;
            }
        }
        else if (neighbour != parent) {
            return true;  // Cycle detected
        }
    }

    return false;
}

    bool validTree(int n, vector<vector<int>>& edges) {

        //1. Build adjacency list
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        //2. initialize
        vector<int> visited(n, 0);
        int count=0;

        //3. count no. of components
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(adj, visited, i);

            }
        }
        if (count != 1) return false;


        //4. check cycle
        //start from i=0. mark parent as visited. if neighbour univisted, do dfs considering the neighbour as parent. if neighbour visited but is not the parent, cycle exists
        vector<int> visitedc(n,0);

        if (n > 0 && cycle_dfs(adj, visitedc, 0, -1)) {
            return false;
        }

        return true;    }
};
