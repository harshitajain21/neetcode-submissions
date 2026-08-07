class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        //check rows
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<9;j++){
                char x=board[i][j];
                if(x!='.'){
                    if(seen.count(x)!=0){
                        return false;
                    }
                    else{
                        seen.insert(x);}}
                }
        }
        
        //check columns - a[i][0] 
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<9;j++){
                char x=board[j][i];
                if(x!='.'){
                    if(seen.count(x)!=0){
                        return false;
                    }
                    else{
                        seen.insert(x);}}
                }
        }
        
        // Check 3x3 boxes
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                unordered_set<char> seen;

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {

                        char x = board[i][j];

                        if (x == '.')
                            continue;

                        if (seen.count(x))
                            return false;

                        seen.insert(x);
                    }
                }
            }
        }

        return true;
    

    }
};
