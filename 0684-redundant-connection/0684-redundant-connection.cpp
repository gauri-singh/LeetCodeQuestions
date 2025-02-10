class Solution {
public:
vector<int> parent;
vector<int> rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        rank.resize(n+1,1);// 1 indexed thats why n+1;
        for(auto pair: edges){
            if(!unionSet(pair[0],pair[1])){
                return pair;
            }
        }
        return {};
    }
    int find(int curr){
        while(curr!=parent[curr]){
            parent[curr]=parent[parent[curr]]; // path compression
            curr=parent[curr];// move upwards
        }
        return curr;
    }
    bool unionSet(int u, int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            //same parent connection already exists, this is redundant
            return false;
        }
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }else{
            //pv is bigger in rank
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        return true;
    }
};
