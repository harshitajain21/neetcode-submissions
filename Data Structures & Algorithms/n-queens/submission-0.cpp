class Solution {
   public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }


void backtrack(vector<vector<string>>& result,
               vector<string>& board,
                              int row,
                                             int n) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // block/place queen
            board[row][col] = 'Q';

            // solve remaining rows
            backtrack(result, board, row + 1, n);

            // UNDO
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    /*N Queens

    so first of all it has to be on different rows and different column
    it cant be on any diagonal lines. for example if i,j is blocked then you cant block i+1,j+1,  or
    i+1, j-1, or i-1,j+1, or i-1,j-1

    so start from 1st row.. block first element and backtrack for remaining rows keeping diagonal
    conditions in mind

    now undo and block 2nd element and same
    */
    vector<vector<string>> result;

    vector<string> board(n, string(n, '.'));

    backtrack(result, board, 0, n);

    return result;
}
}
;
