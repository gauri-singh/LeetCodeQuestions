class Solution {
public:
vector<int> parent;
vector<int> rank;
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,1); // every node is its own parent and every node has rank 1 rn
        int res=n; // initialiaze to n as they are all seperate components
        for(auto edge: edges){
            res-=unionSet(edge[0],edge[1]);
        }
        return res;
    }
    int find( int curr){
        //find the top parent because only the top root is its own parent
        while(curr!=parent[curr]){
            parent[curr]=parent[parent[curr]]; // path compression
            curr=parent[curr];
        }
        return curr;
    }
    int unionSet(int u,int v){
        int pu=find(u); // parent of u
        int pv = find(v);// parent of v
        if(pu==pv){
            return 0; // already connected
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
        else{
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        return 1;
    }
};