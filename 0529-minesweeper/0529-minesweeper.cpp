class Solution {
public:
int ROWS, COLS;
vector<pair<int,int>> dir ={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};// all 8 directions
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
       ROWS=board.size();
       COLS=board[0].size();
       if(board[click[0]][click[1]]=='M'){
        board[click[0]][click[1]]='X';
        return board;
       }
       dfs(board,click[0],click[1]);
       return board;
    }
    void dfs(vector<vector<char>>& board, int r, int c){
        if(r<0 || r>=ROWS || c<0 || c>=COLS || board[r][c] != 'E'){
            return;
        }
        int mines = countMines(board, r, c); // to count neighboring mines
        if(mines>0){
            board[r][c]='0'+mines;// depending on how many mines close by
            return;
        }
        board[r][c]='B';
        for (auto [dr, dc] : dir) {
            dfs(board, r + dr, c + dc);
        }
    }
    int countMines(vector<vector<char>>& board, int r, int c) {
        int count = 0;
        for (auto [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc] == 'M') {
                count++;
            }
        }
        return count;
    }
};