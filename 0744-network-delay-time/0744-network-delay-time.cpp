class Solution {
public:
//using set, same code just used the set to avoid redundancy
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int,int>> st;
        //minheap would have distance and node
        st.insert({0,k});//put source in the minheap with the distance to reach itself which is 0
        unordered_map<int,vector<pair<int,int>>> adj;// adj list would have {node,weight}
        for(auto node : times){
            int u=node[0];int v=node[1];int w=node[2];
            adj[u].push_back({v,w});
        }
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        while(!st.empty()){
            pair<int,int> p=*(st.begin());
            st.erase(p);
            int node= p.second; int path=p.first;
            for(auto& edge : adj[node]){
                int next = edge.first;
                int weight = edge.second;
                if(weight+path < distance[next]){
                    if(distance[next]!=INT_MAX){
                        //we have already visited this node but with a higher distance so it might still be in the set therefore lets remove it
                        st.erase({distance[next],next});// prev distance and the node
                    }
                    //this new path is shorter than prev path
                    distance[next]=weight+path;
                    st.insert({weight+path,next});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(distance[i] == INT_MAX) return -1;
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};


/*
Priority Queue
class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        //minheap would have distance and node
        minheap.push({0,k});//put source in the minheap with the distance to reach itself which is 0
        unordered_map<int,vector<pair<int,int>>> adj;// adj list would have {node,weight}
        for(auto node : times){
            int u=node[0];int v=node[1];int w=node[2];
            adj[u].push_back({v,w});
        }
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        while(!minheap.empty()){
            pair<int,int> p=minheap.top();
            minheap.pop();
            int node= p.second; int path=p.first;
            for(auto& edge : adj[node]){
                int next = edge.first;
                int weight = edge.second;
                if(weight+path < distance[next]){
                    //this new path is shorter than prev path
                    distance[next]=weight+path;
                    minheap.push({weight+path,next});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(distance[i] == INT_MAX) return -1;
            maxTime = max(maxTime, distance[i]);
        }

        return maxTime;
    }
};*/
