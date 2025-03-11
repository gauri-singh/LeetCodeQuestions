class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int> output;
        unordered_map <int, vector<int>> adj;
        // build adjacency list and indegree array
        for (auto edges: prerequisites) {
            int course = edges[0], prereq = edges[1];
            adj[prereq].push_back(course); // prereq → course
            indegree[course]++; // course depends on prereq
        }
        //add all the subjects with no prereqs i.e, 0 indegree to the queue;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
         // Perform topological sort
        while (!q.empty()) {
            int zero = q.front();// get the element from queue
            q.pop();// remove it from map
            output.push_back(zero);// add it to ordering
            //decrement the indegree of affected nodes
            for (auto nextCourse: adj[zero]) {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If we couldn't take all courses, return an empty array
        if (output.size() != numCourses) {
            return {};
        }

        return output;
    }
};
/*Neetcode:
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
};*/