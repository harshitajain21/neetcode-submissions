class Solution {
public:

    bool cycle_dfs(vector<vector<int>>& adj,
                   vector<int>& visited,
                   int node, int target) {

        if (node == target)
            return true;

        visited[node] = 1;

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (cycle_dfs(adj, visited, neighbour, target))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            vector<int> visited(n + 1, 0);

            // Check if a path already exists from u to v
            if (cycle_dfs(adj, visited, u, v)) {
                return edge;
            }

            // No path exists, so safely add the edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};