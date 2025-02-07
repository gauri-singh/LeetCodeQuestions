class Solution {
public:
int ROWS, COLS;
int fresh=0;
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size(), COLS = grid[0].size();
        queue<pair<int,int>> q;
        for(int i =0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]==1){
                    fresh++; // to store number of fresh fruits
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time =0;
        while(!q.empty() && fresh>0){
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                makeRotten(r+1,c,grid,q);
                makeRotten(r-1,c,grid,q);
                makeRotten(r,c+1,grid,q);
                makeRotten(r,c-1,grid,q);
            }
            time++;
        }
        return fresh>0? -1 : time;
    }
    void makeRotten(int r,int c, vector<vector<int>> & grid, queue<pair<int,int>>& q){
        if(r<0 || r>=ROWS || c<0 || c>=COLS || grid[r][c]!=1){
            return;
        }
        //make rotten:
        q.push({r,c}) ; //push to the queue, to spread the rot 
        grid[r][c]=2;
        fresh--;
    }
};