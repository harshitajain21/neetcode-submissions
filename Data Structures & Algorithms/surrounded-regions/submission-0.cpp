class Solution {
public:

/*ex: Input: board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","O","O","X"],
  ["X","O","X","X"]]
-> here, nothing will be changed as there are no surrounded regions
*/

//so basically start with edges of board, wherever o is there on edge, try to make a connected region with that and mark it visited

//now check if there is any unvisited o left, and convert that to x
    
void dfs(vector<vector<char>>& board,
         vector<vector<bool>>& visited,
         int i, int j) {

    int n = board.size();
    int m = board[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m)
        return;

    if (board[i][j] != 'O' || visited[i][j])
        return;

    visited[i][j] = 1;

    dfs(board, visited, i - 1, j); // up
    dfs(board, visited, i + 1, j); // down
    dfs(board, visited, i, j - 1); // left
    dfs(board, visited, i, j + 1); // right
}

    void solve(vector<vector<char>>& board) {


        //empty board
        if (board.empty() || board[0].empty()){
            return;}
        
        
        int n=board.size();
        int m = board[0].size();

        //1. store coordinates of all edges O in edgeso vector
        vector<vector<int>> edgeso;
        for(int i=0; i<m;i++){
            if(board[0][i]=='O'){
                edgeso.push_back({0,i});
            }
            if(board[n-1][i]=='O'){
                edgeso.push_back({n-1,i});
            }
        }
        for(int j=0; j<n;j++){
            if(board[j][0]=='O'){
                edgeso.push_back({j,0});
            }
            if(board[j][m-1]=='O'){
                edgeso.push_back({j,m-1});
            }
        }

        //2. try to make a connected region with edgeso and mark it visited
        vector<vector<bool>> visited (n, vector<bool>(m,0));
        for(auto edge: edgeso){
            dfs(board, visited, edge[0], edge[1]);
        }

        // 3. Convert unvisited O's to X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }

    }
};
