class Solution {
public:
int ROWS,COLS;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        ROWS=image.size(), COLS=image[0].size();
        if(oldColor!=color){
            dfs(sr,sc,color,oldColor,image);
        }
        return image; 
    }
    void dfs(int sr,int sc, int color, int oldColor, vector<vector<int>>& image){
        if(sr>=0 && sr<ROWS && sc>=0 && sc<COLS && image[sr][sc]==oldColor){
            image[sr][sc]=color;
            dfs(sr+1,sc,color,oldColor,image);
            dfs(sr-1,sc,color,oldColor,image);
            dfs(sr,sc+1,color,oldColor,image);
            dfs(sr,sc-1,color,oldColor,image);
        }
        return;
    }
};/*BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color){
            return image;
        }
        int ROWS=image.size(), COLS=image[0].size();
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue <pair<int,int>> bfs;
        bfs.push({sr,sc});
        image[sr][sc]=color;
        while(!bfs.empty()){
            int size=bfs.size();
            for(int i=0;i<size;i++){
                int r=bfs.front().first;
                int c=bfs.front().second;
                bfs.pop();
                for(auto [dr,dc] : dir){
                    int currR=dr+r, currC=dc+c;
                    if(currR>=0 && currR<ROWS && currC>=0 && currC<COLS && image[currR][currC]==oldColor){
                        image[currR][currC]=color;
                        bfs.push({currR,currC});
                    }
                }
            }
        }
        return image;
    }
};*/