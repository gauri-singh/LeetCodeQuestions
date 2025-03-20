class Solution {
public:
map<pair<int,int>,pair<int,int>> source;
int ROWS,COLS;
map<pair<int,int>, int> area;
set<pair<int,int>> seen;
int maxArea=0;
    int largestIsland(vector<vector<int>>& grid) {
         ROWS=grid.size(); COLS=grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]==1){
                    dfs(i,j,{i,j},grid); //Precompute all the details in regards to all Islands
                }
            }
        }
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                seen.clear();
                if(grid[i][j]==0){
                     // from each zero, go in all 4 directions and see if they are an island 
                    checkNeighbors(i-1,j,grid);
                    checkNeighbors(i+1,j,grid);
                    checkNeighbors(i,j+1,grid);
                    checkNeighbors(i,j-1,grid);
                    //iterate over all the parents of each island and get the area of each island
                    int currArea=1;
                    for(auto key : seen){
                        currArea+=area[key];
                    }
                    maxArea=max(maxArea,currArea);
                }
            }
        }

        return maxArea;
    }
    void checkNeighbors(int r,int c,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=ROWS || c>=COLS  || grid[r][c]==0){
            return;
        }
        pair<int,int> parent=source[{r,c}];
        seen.insert(parent);
    }
    void dfs(int r,int c,pair<int,int> parent,vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=ROWS || c>=COLS  || grid[r][c]!=1){
            return;
        }
        grid[r][c]=2;
        area[parent]++;// for each "parent" of the island i.e, start of the island, keep the area calculates
        source[{r,c}]=parent; // for each island, mark its parent so we can find area of the island from any entry point easily
        maxArea=max(maxArea,area[parent]); // to know the largest island
        dfs(r+1,c,parent,grid);
        dfs(r-1,c,parent,grid);
        dfs(r,c+1,parent,grid);
        dfs(r,c-1,parent,grid);

    }
};