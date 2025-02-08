class Solution {
public:
unordered_map <int, vector<int>> preMap;
unordered_set<int> visit,cycle;
vector<int> output;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto courseList : prerequisites){
            preMap[courseList[0]].push_back(courseList[1]);
        }
 
        for(int subj=0;subj<numCourses;subj++){
            if(!dfs(subj))
                return {};
        }
        return output;
    }

    bool dfs(int subj){
        if(cycle.count(subj)){
            return false;     
        }
        if(visit.count(subj)){
                return true; // using this to not visit the same set again like clearing the hashmap in course schedule 1 
                            //to return if this is already visited and we know theres no cycle 
        }
        cycle.insert(subj);
        for(auto pre : preMap[subj]){
            if(!dfs(pre)){
                return false;
            }
        }
        cycle.erase(subj);
        visit.insert(subj);
        output.push_back(subj);
        return true;
    }
};