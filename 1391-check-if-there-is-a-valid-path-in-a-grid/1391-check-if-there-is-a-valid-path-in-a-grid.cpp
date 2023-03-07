class Solution {
public:
vector<vector<int>> g;
int n,m;
    bool hasValidPath(vector<vector<int>>& grid) {
        g=grid;
       n=grid.size();
       m=grid[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,false));
       dfs(0,0,vis);
       return vis[n-1][m-1]; 
    }
    void dfs(int ux,int uy,vector<vector<bool>>& vis ){
       
        int vx,vy;
        vis[ux][uy]=true;
         //Right Exit
        if(g[ux][uy]==1 || g[ux][uy]==4 || g[ux][uy]==6){ vx=ux,vy=uy+1; if(isValid(vx,vy,vis) && L_Enter(vx,vy)){dfs(vx,vy,vis);}}
        //Left Exit
        if(g[ux][uy]==1 || g[ux][uy]==3 || g[ux][uy]==5){ vx=ux,vy=uy-1; if(isValid(vx,vy,vis) && R_Enter(vx,vy)){dfs(vx,vy,vis);}}
        //Up Exit
        if(g[ux][uy]==2 || g[ux][uy]==5 || g[ux][uy]==6){ vx=ux-1,vy=uy; if(isValid(vx,vy,vis) && D_Enter(vx,vy)){dfs(vx,vy,vis);}}
        //Down Exit
        if(g[ux][uy]==2 || g[ux][uy]==4 || g[ux][uy]==3){ vx=ux+1,vy=uy; if(isValid(vx,vy,vis) && U_Enter(vx,vy)){dfs(vx,vy,vis);}}
    }
    bool isValid(int x,int y,vector<vector<bool>>& vis){
        if(x>=0 && x<=n-1 && y>=0 && y<=m-1 && !vis[x][y]) return true;
        return false;
    }

    bool L_Enter(int x,int y){
        if(g[x][y]==1 || g[x][y]==3 || g[x][y]==5) return true;
        return false;
    }
    bool R_Enter(int x,int y){
        if(g[x][y]==1 || g[x][y]==4 || g[x][y]==6) return true;
        return false;
    }
    bool D_Enter(int x,int y){
        if(g[x][y]==2 || g[x][y]==3 || g[x][y]==4) return true;
        return false;
    }
    bool U_Enter(int x,int y){
        if(g[x][y]==2 || g[x][y]==5 || g[x][y]==6) return true;
        return false;
    }
};