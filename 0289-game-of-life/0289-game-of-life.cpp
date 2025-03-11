class Solution {
public:
int ROWS,COLS;
set<pair<int,int>> visited;
    void gameOfLife(vector<vector<int>>& board) {
        ROWS=board.size(), COLS=board[0].size();
        set<pair<int,int>> ones;// to retrive cells with ones in it
        queue<pair<int,int>> q;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j]==1){
                    q.push({i,j});
                    ones.insert({i,j});
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
               int r =q.front().first;
               int c=q.front().second;
                q.pop();
                incrementCount(r-1,c+1,board);
                incrementCount(r+1,c-1,board) ;
                incrementCount(r-1,c-1,board);
                incrementCount(r+1,c+1,board);
                incrementCount(r+1,c,board);
                incrementCount(r-1,c,board);
                incrementCount(r,c+1,board);
                incrementCount(r,c-1,board);
            }
        }

        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(ones.count({i, j})) {
                // Originally live cell: survives if its count is 3 or 4.
                    board[i][j] = (board[i][j] == 3 || board[i][j] == 4) ? 1 : 0;
                }else {
                    // Originally dead cell: becomes live only if it has exactly 3 live neighbors.
                    board[i][j] = (board[i][j] == 3) ? 1 : 0;
                }
            }
        }

    }
    void incrementCount(int r, int c,vector<vector<int>>& board){
        if(r>=ROWS || r<0 || c>=COLS || c<0){
            return ;
        }
        board[r][c]++;
    }
};