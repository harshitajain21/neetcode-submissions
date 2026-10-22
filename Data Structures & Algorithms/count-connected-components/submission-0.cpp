class Solution {
public:

/*
1. Build adjacency list
2. for ex: [[1],[0,2],[1],[4],[3]]
3. start from n=0, not visited count++, mark visited, check its adj list, do dfs at each point and mark visited
4. n++, if not visited, count++ , do dfs .. and so on
*/

    void dfs(vector<vector<int>> &adj, vector<int> &visited, int node ){        
        visited[node]=true;

        for (int neighbour : adj[node]) { 
            if (!visited[neighbour]) {
                dfs(adj, visited, neighbour);
        }
    }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        //1. Build adjacency list
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        //2. initialize
        vector<int> visited(n, 0);
        int count=0;

        //3. 
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                count++;
                dfs(adj, visited, i);

            }
        }

        return count;
 
    }
};
