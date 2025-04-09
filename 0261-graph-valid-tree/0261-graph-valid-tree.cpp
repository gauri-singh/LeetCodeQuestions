class Solution {
public:
vector<int> parent;
vector<int> rank;
unordered_map<int,vector<int>> adj;
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            //not fully connected
            return false;
        }
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        rank.resize(n,0);
        for(auto edge: edges){
            if(!unionSet(edge[0],edge[1])){
                return false;
            }
        }
        return true;
    }
    int find(int curr){
        while(curr!=parent[curr]){
            parent[curr]=parent[parent[curr]];
            curr=parent[curr];
        }
        return curr;
    }
    bool unionSet(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            //already connected cycle detected
            return false;
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }else{
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        return true;
    }
};