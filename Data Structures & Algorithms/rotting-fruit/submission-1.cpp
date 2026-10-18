class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        //same as prv question.. instead of 0 put all 2s in queue then process of adding all neighbours (up, down, right, left) in queue and marking them as 2 ,,per minute..count total minutes .. now finally check whole grid if any 1 is left

//Increment minutes: Increase the time by one if at least one fresh orange rots during that level - s

        //1. INITIALISING
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int total_minutes=0;

        //2. adding all 0 cells in queue
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    }}}

        //3. processing queue one by one
        while(!q.empty()){

            int og_size=q.size();
            bool rotted = false;

                //process each cell, check up,down,left, right, if 1 is found, update it to 2 and that cell to queue

            for(int k=0; k<og_size;k++){  //process queue level by level, so we can rot minute by minute
            //k represents no. of nodes/oranges processed from the queue within the current minute.. SO AS WE PROCEED WE ADD FURTHER NODES TO QUEUE, BUT WE DONT WANT TO PROCESS THOSE NODES IN THIS MINUTE, THATS WHY WE PRESERVE ORIGINAL SIZE and only process till original queue is empty
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first;
                int j=p.second;

                // Up
                //note: i-1>=0 condition has to be written before
                if (i-1>=0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                    rotted=true;
                }

                // Down
                if (i + 1 < m && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                    rotted=true;
                }

                // Left
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                    rotted=true;
                }

                // Right
                if (j + 1 < n && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                    rotted=true;
                }}

                // Increment only if at least one orange rotted
            if (rotted) {
                total_minutes++;
            }
            }

        // 4.Check whether any fresh oranges remain
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return total_minutes;
    }
};
