class TicTacToe {
public:
    // rows[row][0] tracks Player 1's moves in row 'row'
    // rows[row][1] tracks Player 2's moves in row 'row'
    vector<vector<int>> rows;
    // cols[col][0] tracks Player 1's moves in column 'col'
    // cols[col][1] tracks Player 2's moves in column 'col'
    vector<vector<int>> cols;
    // d1[0] tracks Player 1's moves in the leading diagonal (x == y)
    // d1[1] tracks Player 2's moves in the leading diagonal
    vector<int> d1;
    // d2[0] tracks Player 1's moves in the reverse diagonal (x + y == n-1)
    // d2[1] tracks Player 2's moves in the reverse diagonal
    vector<int> d2;

    int n; // Size of the board (n x n)
    TicTacToe(int n) {
        this->n = n;
        rows = vector<vector<int>>(n, vector<int>(2, 0));
        cols = vector<vector<int>>(n, vector<int>(2, 0));
        d1 = vector<int>(n, 0);
        d2 = vector<int>(n, 0);
    }

    int move(int row, int col, int player) {
        player--; // so that it becomes 0 indexed
        rows[row][player]++;
        cols[col][player]++;
        if (row == col) {
            d1[player]++;
        }
        if (row + col == n - 1) {
            d2[player]++;
        }

        // check win
        if (rows[row][player] == n || cols[col][player] == n ||
            d1[player] == n || d2[player] == n) {
            return player + 1; // 1 indexed again
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */