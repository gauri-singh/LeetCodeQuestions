class Solution {
public:
struct compare{
    bool operator()(vector<int> a, vector<int> b){
        int dist1= a[0]*a[0]+a[1]*a[1];
        int dist2= b[0]*b[0]+b[1]*b[1]; // eucledian distance from origin and avoiding sqrt for precision errors and efficiency
        return dist1>dist2;
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> heap; // minheap of closest to origin
        vector<vector<int>> result;
        for(auto point: points){
            heap.push(point);
        }
        while(!heap.empty() && k){
            result.push_back(heap.top());
            heap.pop();
            k--;
        }
        return result;
    }
};