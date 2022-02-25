class Solution {
public:
   int count = 0;
    bool isvalid(vector<string> &board, int col, int row)
    {
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void Nqueen(vector<string> &board, int row, int n)
    {
        if (row == n)
        {
            count++;
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isvalid(board, col, row))
            {
                board[row][col] = 'Q';
                Nqueen(board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        if (n <= 0)
            return {{}};
        vector<string> board(n, string(n, '.'));
        Nqueen(board, 0, n);
        return count;
    }
};
