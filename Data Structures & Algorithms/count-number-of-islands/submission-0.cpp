class Solution {
public:

    void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j ){

        int m = grid.size();
        int n = grid[0].size();
        // Base case: out of bounds, water, or already visited
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == '0' || visited[i][j] == 1) {
            return;
        }

        // Mark current cell as visited
        visited[i][j] = 1;

        // Explore all four directions
        dfs(grid, visited, i - 1, j);  // Up
        dfs(grid, visited, i + 1, j);  // Down
        dfs(grid, visited, i, j - 1);  // Left
        dfs(grid, visited, i, j + 1);  // Right

    }


    int numIslands(vector<vector<char>>& grid) {
        
        //An island
            //1. forms a group (horizontally or vertically connected)
            //2. is surrounded by water
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //grid[i][j]
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    //now do dfs - i.e see all neighbours(horizontally and vertically and mark visited)
                    dfs(grid, visited, i,j);
                }
            }
        }
        return count;
    }
};
