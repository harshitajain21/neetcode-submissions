class Solution {
public:

// its the same as prv one just area++ for each visited and update maxareaa

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j , int&area, int &maxarea){

        int m = grid.size();
        int n = grid[0].size();
        // Base case: out of bounds, water, or already visited
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 0 || visited[i][j] == 1) {
            return;
        }

        // Mark current cell as visited
        visited[i][j] = 1;
        area++;
        maxarea=max(maxarea, area);

        // Explore all four directions
        dfs(grid, visited, i - 1, j,area, maxarea);  // Up
        dfs(grid, visited, i + 1, j, area, maxarea);  // Down
        dfs(grid, visited, i, j - 1, area, maxarea);  // Left
        dfs(grid, visited, i, j + 1, area, maxarea);  // Right

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        //An island
            //1. forms a group (horizontally or vertically connected)
            //2. is surrounded by water
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int count = 0;
        int maxarea=0;
        int area;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //grid[i][j]
                if(grid[i][j]==1 && visited[i][j]==0){
                    area=0;
                    count++;
                    //now do dfs - i.e see all neighbours(horizontally and vertically and mark visited)
                    dfs(grid, visited, i,j, area,maxarea);
                }
            }
        }
        return maxarea;
    }
    };
