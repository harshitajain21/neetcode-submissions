class Solution {
public:

//create an adjacency list where two words are connected if they differ by exactly one character, then use BFS to find the shortest path.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size();

        vector<string> words = wordList;
        words.push_back(beginWord);

        vector<vector<int>> adj(n + 1);

        // Build adjacency list
        for(int i = 0; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {

                int diff = 0;

                for(int k = 0; k < words[i].size(); k++) {
                    if(words[i][k] != words[j][k])
                        diff++;
                }

                if(diff == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Find endWord index
        int target = -1;

        for(int i = 0; i < n; i++) {
            if(words[i] == endWord)
                target = i;
        }

        if(target == -1) return 0;

        // BFS
        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.push(n);
        visited[n] = true;

        int steps = 1;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                int node = q.front();
                q.pop();

                if(node == target)
                    return steps;

                for(int neighbour : adj[node]) {
                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};