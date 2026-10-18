class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

                //grid[i][j]
                //dfs up, down, left, right until you reach 0 and update min distance

                /*at grid[i][j] check up,left, right, down : if you found inf, go there and distance++ , and repeat the whole thing
                then when you find 0, distance++ and update inf to mindistance found yet.. path end..then explore remaining paths
                so we need to preserve original distance
                also no need of visited i think we essentially just need paths*/

                //BUT NOTE : BFS explore all cells at distance 1 before cells at distance 2, all cells at distance 2 before distance 3, and so on.

                //SO BFS EXPLORES IN ASCENDING ORDER DISTANCE .. SO USE BFS
                //at each point do bfs up left down right - if inf is there, put in queue, otherwise if you reach 0 update mindiist

                //OK BUT WE CAN DO OPP.. PUT ALL 0 CELSS IN QUEUE, MOVE OUTWARDS.. WHEN YOU REACH CELL WITH INF -> PUT MINDIST = CURR_DIST+1..push neigbour to queue


        //1. INITIALISING
        int m = grid.size();
        int n = grid[0].size();
        int INF = 2147483647;
        queue<pair<int,int>> q;

        //2. adding all 0 cells in queue
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    }}}

        //3. processing queue one by one
        while(!q.empty()){

            //process each cell, check up,down,left, right, if inf is found, then update distance=distance till that cell(from 0)+1 and push it to queue
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

                /*if(grid[i-1][j]==INF){
                    grid[i-1][j]=grid[i][j]+1;
                    q.push({i-1,j});
                }*/

            // Up
            //note: i-1>=0 condition has to be written before
            if (i-1>=0 && grid[i - 1][j] == INF) {
                grid[i - 1][j] = grid[i][j] + 1; //distance till cell[i][j] (from 0) has already been updated and is grid[i][j]
                q.push({i - 1, j});
            }

            // Down
            if (i + 1 < m && grid[i + 1][j] == INF) {
                grid[i + 1][j] = grid[i][j] + 1;
                q.push({i + 1, j});
            }

            // Left
            if (j - 1 >= 0 && grid[i][j - 1] == INF) {
                grid[i][j - 1] = grid[i][j] + 1;
                q.push({i, j - 1});
            }

            // Right
            if (j + 1 < n && grid[i][j + 1] == INF) {
                grid[i][j + 1] = grid[i][j] + 1;
                q.push({i, j + 1});
            }
            }
    }
};
