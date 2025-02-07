class Solution {
public:
unordered_map<int,vector<int>> preMap; // adjancey list
unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& pre : prerequisites){
            preMap[pre[0]].push_back(pre[1]);
            
        }
        for(int course =0;course<numCourses ;course++){
            if(!dfs(course)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int subj){
        if(visited.count(subj)){
            return false;
        }
        if(preMap[subj].empty()){
            return true;
        }
        visited.insert(subj);
        for(auto pre : preMap[subj]){
            if(! dfs(pre)){
                return false;
            }
        }
        preMap[subj]={}; // so that next time we visit this we can return true immediately
        visited.erase(subj); // remove from visited list for next subject since for thsi subject dfs is done
        return true; 
    }
};