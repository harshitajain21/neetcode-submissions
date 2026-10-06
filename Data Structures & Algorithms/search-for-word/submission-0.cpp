class Solution {
public:


    bool backtr(vector<vector<char>>& board, string& word, int i, int j, int k) {

        // We found the complete word
        if (k == word.size()) {
            return true;
        }

        // Out of bounds
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }

        // Current letter doesn't match
        if (board[i][j] != word[k]) {
            return false;
        }

        // Store current letter and mark as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Try moving in all 4 directions

        // down
        if (backtr(board, word, i + 1, j, k + 1))
            return true;

        // up
        if (backtr(board, word, i - 1, j, k + 1))
            return true;

        // right
        if (backtr(board, word, i, j + 1, k + 1))
            return true;

        // left
        if (backtr(board, word, i, j - 1, k + 1))
            return true;

        // Undo
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        //if we only move forward, at any point (i,j) we can go to (i,j+1) or (i+1,j)

        //so find the first letter

        /*i=0;

        letter=word[i];

        int k=0;
        for(int j=0;j<board[0].size(); j++){
            if(board[k][j]==letter){
                int found=j;
                break;
            }
        }

        i++;

        letter=word[i];

        if(board[k][found+1]==word || board[k+1][found]){
            backtr()
        }

        else{ //search again*/

        // Find the first letter
        for (int i = 0; i < board.size(); i++) {

            for (int j = 0; j < board[0].size(); j++) {

                if (board[i][j] == word[0]) {

                    // Start backtracking from here
                    if (backtr(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
