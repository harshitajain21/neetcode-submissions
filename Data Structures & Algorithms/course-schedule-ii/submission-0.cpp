class Solution {
public:


        bool dfscycle(int node, vector<vector<int>>& adj,
              vector<int>& state, vector<int>& ans) {

    state[node] = 1;

    for (int neighbour : adj[node]) {
        if (state[neighbour] == 1) return true;

        if (state[neighbour] == 0 &&
            dfscycle(neighbour, adj, state, ans))
            return true;
    }

    state[node] = 2;

    ans.push_back(node);  // NEW LINE

    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {


        int n=numCourses;
        vector<vector<int>> adj(n);
        for(auto prereq_pair: prerequisites){
            adj[prereq_pair[1]].push_back(prereq_pair[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> ans; //NEW LINE
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && dfscycle(i, adj, state,ans))
                return {};
        }


        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
