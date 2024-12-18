class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> combined;
        int n=speed.size();
        for(int i=0;i<n;i++){
            combined.push_back({position[i],speed[i]});
        }
        sort(combined.begin(),combined.end());
        double prevTime= (double)(target-combined[n-1].first)/combined[n-1].second;
        int fleet=1;
        for(int i=n-2;i>=0;i--){
            double currTime=(double)(target-combined[i].first)/combined[i].second;
            if(currTime>prevTime){
                fleet++;
                prevTime=currTime;
            }
        }
        return fleet;
    }
};