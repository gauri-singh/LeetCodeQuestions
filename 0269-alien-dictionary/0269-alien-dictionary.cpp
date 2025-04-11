class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;
        for(auto word: words){
            for(char ch: word){
                adj[ch]=unordered_set<char>();// initialize all unique character i.e, nodes
                indegree[ch]=0;
            }
        }

        for(int i=0;i+1<words.size();i++){
            string w1=words[i], w2=words[i+1];
            int minLen= min(w1.size(),w2.size());// to find the difference between two sorted strings
            if(w1.size()>w2.size() && w1.substr(0,minLen)==w2.substr(0,minLen)){
                return "";// edge case =>eg if apes came before ape in our human dict
            }
            for(int j=0;j<minLen;j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        //add to the set if doesnt exist already in the map
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        //kahn's
        queue<char> q;
        for(auto& [ch,degree]: indegree){
            if(degree==0){
                q.push(ch);
            }
        }
        string res="";
        while(!q.empty()){
            char curr= q.front(); q.pop();
            res+=curr;
            for(auto next : adj[curr]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return res.length()==indegree.size()?res:"";// if size isnt the same then it is a cycle
    }
};
