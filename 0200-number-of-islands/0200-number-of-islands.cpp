class Solution {
public:
int ROWS, COLS;
set<pair<int,int>> visited;
int islands =0;
int directions [4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        ROWS= grid.size(), COLS = grid[0].size();
        for(int r =0;r<ROWS;r++){
            for(int c =0;c<COLS;c++){
                if(grid[r][c]=='1' && !visited.count({r,c})){
                    //dfs(r,c,grid);
                     bfs(r,c,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    // void dfs( int r,int c,vector<vector<char>>& grid ){
    //     if(r<0 || r>=ROWS || c<0 || c>=COLS || visited.count({r,c}) || grid[r][c]!='1'){
    //         return;
    //     }
    //     visited.insert({r,c});
    //     dfs(r+1,c,grid);
    //     dfs(r-1,c,grid);
    //     dfs(r,c+1,grid);
    //     dfs(r,c-1,grid);
    // }

void bfs(int r, int c,vector<vector<char>>& grid){
    queue <pair<int,int>> q;
    q.push({r,c});
    visited.insert({r,c});
    int row, col;
    while(!q.empty()){
        row = q.front().first;
        col = q.front().second;
        q.pop();
        //going in all 4 directions to see if land or not
        for(auto & [dr,dc] : directions){
            int currRow= row+dr;
            int currCol = col+dc;
            if(currRow>=0 && currRow<ROWS && currCol>=0 && currCol<COLS && grid[currRow][currCol]=='1' && !visited.count({currRow,currCol})){
                q.push({currRow,currCol});
                visited.insert({currRow,currCol});
            }
        }
    }
}
};