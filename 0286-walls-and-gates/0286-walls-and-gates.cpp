class Solution {
public:
int ROWS,COLS;

    void wallsAndGates(vector<vector<int>>& rooms) {
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int INF = 2147483647;
        ROWS = rooms.size(); COLS = rooms[0].size();
        queue<pair<int,int>> q;
        for(int i =0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int distance=0,size,r,c,currR,currC;
        while(!q.empty()){
            size=q.size();
            distance++;
            for(int i=0;i<size;i++){
                 r= q.front().first;
                 c= q.front().second; 
                q.pop();
                for(auto& [dr,dc] : dir){
                    currR=r+dr; currC=c+dc;
                    if(currR>=0 && currR<ROWS &&  currC>=0 && currC<COLS && rooms[currR][currC]==INF ){
                        //empty room spotted;
                        q.push({currR,currC});
                        rooms[currR][currC]=distance;
                    }
                }
            }
        }
    }
};