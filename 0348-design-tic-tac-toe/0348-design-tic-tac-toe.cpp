class TicTacToe {
public:
vector<vector<int>> rows,cols;
vector<int> posDiag;
vector<int> negDiag;
int n;
    TicTacToe(int n) {
        this->n=n;
        rows=vector<vector<int>>(n,vector<int>(2,0));
        cols=vector<vector<int>>(n,vector<int>(2,0));
        posDiag=vector<int>(2,0);
        negDiag=vector<int>(2,0);
    }
    
    int move(int row, int col, int player) {
        player--;
        rows[row][player]++;
        cols[col][player]++;
        if(row==col){
            posDiag[player]++;
        }
        if((row+col)==n-1){
            negDiag[player]++;
        }
        //checking if this move made the player win
        if(rows[row][player] == n || cols[col][player] ==n || posDiag[player]==n || negDiag[player]==n){
            return player+1;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */