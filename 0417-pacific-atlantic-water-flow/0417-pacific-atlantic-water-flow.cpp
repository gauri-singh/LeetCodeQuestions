class Solution {
public:
int ROWS,COLS;
    void dfs( int r, int c,vector<vector<int>>& heights, set<pair<int,int>>& ocean , int prevH){
        if(r<0 ||r>=ROWS || c<0 ||c>=COLS || ocean.count({r,c}) || heights[r][c]<prevH){
            return;
        }
        ocean.insert({r,c});
        dfs(r+1,c,heights,ocean,heights[r][c]);
        dfs(r-1,c,heights,ocean,heights[r][c]);
        dfs(r,c+1,heights,ocean,heights[r][c]);
        dfs(r,c-1,heights,ocean,heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>> atlantic, pacific;
        ROWS = heights.size(), COLS = heights[0].size();
        int c,r;
        for( c=0;c<COLS;c++){
            dfs(0,c,heights,pacific,heights[0][c]); // pacific
            dfs(ROWS-1,c,heights,atlantic,heights[ROWS-1][c]); // atlantic
        }
        for(r=0;r<ROWS;r++){
            dfs(r,0,heights,pacific,heights[r][0]); // pacific
            dfs(r,COLS-1,heights,atlantic,heights[r][COLS-1]); // atlantic
        }
        vector<vector<int>> res;
        for(r=0;r<ROWS;r++){
            for(c=0;c<COLS;c++){
                if(atlantic.count({r,c}) && pacific.count({r,c})){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};