class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int,int>> coords;
        map<int,int> brightness;
        int currBrightness=0,maxBrightness=INT_MIN,maxIndex;
        for(auto l: lights){
            pair p=make_pair(l[0]-l[1],l[0]+l[1]);
            coords.push_back(p);
            brightness[p.first]++;
            brightness[p.second+1]--;
        }
        for(auto it: brightness){
            currBrightness+=it.second;
            if(currBrightness>maxBrightness){
                maxBrightness=currBrightness;
                maxIndex=it.first;
            }
        }
        return maxIndex;
    }
};