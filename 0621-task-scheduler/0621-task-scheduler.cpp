class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        queue<pair<int,int>> q;
        vector<int> count(26,0);
        for(auto task: tasks){
            count[task-'A']++; // to count frequency of each task
        }
        for(auto it: count){
            if(it>0){
                maxheap.push(it);// push the frequency of each character i.e task
            }
        }
        int time=0,freq=0;
        while(!maxheap.empty() || !q.empty()){
            time++;
            if(maxheap.empty()){
                //process remaining stuff from queue
                time= q.front().second;
            }
            else{
                freq= maxheap.top(); //get most frequent task
                maxheap.pop();
                freq--; // processing task
               if(freq>0)
                    q.push({freq,time+n}); // pushing frequency and when can we execute again
            }
            if(!q.empty() && q.front().second==time){
                //the task in queue is ready to processed now and can be added to the heap for processing
                freq=q.front().first;
                q.pop();
                maxheap.push(freq);
            }
        }
        return time;
    }
};
