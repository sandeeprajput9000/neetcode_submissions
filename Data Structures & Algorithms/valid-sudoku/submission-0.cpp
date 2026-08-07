class Solution {
public:
bool isValid(vector<vector<char>>& board, int r, int c) {
        char ch = board[r][c];

       
        for (int j = 0; j < 9; j++) {
            if (j != c && board[r][j] == ch)
                return false;
        }

    
        for (int i = 0; i < 9; i++) {
            if (i != r && board[i][c] == ch)
                return false;
        }

       
        int sr = 3 * (r / 3);
        int sc = 3 * (c / 3);

        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if ((i != r || j != c) && board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

     bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] != '.') {
                    if (!isValid(board, i, j))
                        return false;
                }

            }
        }

        return true;
    }
   
        
    
};
