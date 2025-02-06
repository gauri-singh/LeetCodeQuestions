class Solution {
public:
int ROWS,COLS;
set<pair<int,int>>visited;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0,currArea;
        ROWS= grid.size(),COLS=grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]==1 && !visited.count({i,j})){
                    currArea = dfs(i,j,grid);
                    maxArea=max(maxArea,currArea);
                }
            }
        }
        return maxArea;
    }
    int dfs(int r,int c,vector<vector<int>>& grid){
        if(r>=ROWS || r<0 || c>=COLS ||c<0 || grid[r][c]==0 || visited.count({r,c})){
            return 0;
        }
        visited.insert({r,c});
        return (1+ ( dfs(r+1,c,grid) + dfs(r-1,c,grid) + dfs(r,c+1,grid)  + dfs(r,c-1,grid))); // 1 is added for current cell

    }
};
// BFS: 
// class Solution {
// public:
// int directions [4][2]={{1,0},{-1,0},{0,1},{0,-1}};
// set<pair<int,int>> visited;
// int ROWS,COLS;
// int maxArea=0;
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         ROWS= grid.size(), COLS=grid[0].size();
//         int currArea;
//         for(int r=0;r<ROWS;r++){
//             for(int c=0;c<COLS;c++){
//                 if(grid[r][c]==1 && !visited.count({r,c})){
//                     currArea = bfs(r,c,grid);
//                     maxArea=max(maxArea,currArea);
//                 }
//             }
//         }
//         return maxArea;
//     }
//     int bfs(int r,int c,vector<vector<int>>& grid){
//         queue<pair<int,int>> q;
//         q.push({r,c});
//         visited.insert({r,c});
//         int area =1;// for the current visiting cell
//         // for the cells in neighbouring directions iteratively
//         while(!q.empty()){
//             r= q.front().first;
//             c=q.front().second;
//             q.pop();
//             for(auto& [dr,dc] : directions){
//                 int currR=r+dr;
//                 int currC=c+dc;
//                 if(currR>=0 && currR<ROWS && currC>=0 && currC<COLS && grid[currR][currC]==1 && !visited.count({currR,currC})){
//                     q.push({currR,currC});
//                     visited.insert({currR,currC});
//                     area++;
//                 }
//             }
//         }
//         return area;
//     }
// };
