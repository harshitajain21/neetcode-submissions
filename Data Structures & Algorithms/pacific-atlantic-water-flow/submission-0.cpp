class Solution {
public:

    int n, m;

//heights[r][c] : height above sea level of cell at [r,c]

    void dfs(vector<vector<int>> &heights, vector<vector<int>> &ocean_cells, int i, int j){

        if(ocean_cells[i][j]==0){
            ocean_cells[i][j]=1;}
        else{
            return;
        }
        
        //up
        if (i - 1 >= 0 && !ocean_cells[i - 1][j] && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, ocean_cells, i - 1, j);
        }

        //down
        if (i + 1 < n && !ocean_cells[i + 1][j] && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, ocean_cells, i + 1, j);
        }

        //right
        if(j+1<m && ocean_cells[i][j+1]==0 && heights[i][j+1]>=heights[i][j]){
            dfs(heights, ocean_cells, i,j+1);
        }

        //left
        if (j - 1 >= 0 && !ocean_cells[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, ocean_cells, i, j - 1);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        /*nxm
        pacific ocean: [0,0], [0,1], ... [0,n-1]  +  [1,0], [2,0]... [m-1,0]
        atlantic ocean: [m-1,0], [m-1,1]..[m-1, n-1]  +  [0,n-1],[1,n-1],..[m-1,n-1]*/

        //lets take [1,2] i.e the 6 in middle.. now we want to take it to atlantic ocean first so we cant go up atleast
        //so look left, down, right : if you find no. less than current, move there and mark visited then proceed further using DFS.. now if you reach any cell in atlantic ocean list, then add that to our result
        //for pacific ocean, Same but move up, left, right

//BETTER APPROACH : START FROM WATER, AND MOVE TOWARDS LARGER, MARK BOTH P AND A , IF P CAN VISIT IT THEN MARK P, IF A CAN VISIT IT MARK A, AND IF A CELL IS MARKED BOTH P AND A, THEN ADD IT TO RESULT

//TO MARK P AND A : USE 2 VISITED MATRIX

    //1. Initialising
    n=heights.size();
    m=heights[0].size();
    vector<vector<int>> pacific_cell (n, vector<int>(m,0));
    vector<vector<int>> atlantic_cell(n, vector<int>(m,0));

    //2. traversing pacific cells : [0,0], [0,1], ... [0,n-1]  +  [1,0], [2,0]... [m-1,0]
    int i=0;
    for(int j=0;j<m;j++){//heights[0,j]
        dfs(heights, pacific_cell, i, j);
    }

    int k=0;
    for(int l=0;l<n;l++){
        dfs(heights, pacific_cell, l,k);
    }

    //3. traversing atlantic cells: [m-1,0], [m-1,1]..[m-1, n-1]  +  [0,n-1],[1,n-1],..[m-1,n-1]
    i=n-1;
    for(int j=0;j<m;j++){//heights[0,j]
        dfs(heights, atlantic_cell, i, j);
    }

    k=m-1;
    for(int l=0;l<n;l++){
        dfs(heights, atlantic_cell, l,k);
    }

    //4. checking which cells have both pacific and atlantic marked
    vector<vector<int>> result;
    for(int s=0;s<n;s++){
        for(int t=0; t<m; t++){
            if(pacific_cell[s][t]==1 && atlantic_cell[s][t]==1){
                result.push_back({s,t});
            }
        }}

            return result;

    }


};
