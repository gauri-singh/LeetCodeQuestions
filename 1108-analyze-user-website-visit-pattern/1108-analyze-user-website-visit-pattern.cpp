class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> userVisits;
        for (int i = 0; i < username.size(); ++i) {
            userVisits[username[i]].emplace_back(timestamp[i], website[i]);
            // pushing back pair also work, but emplacing is faster
        }
        
        map<vector<string>, int> websiteCount;
        
        for (auto& userEntry : userVisits) {
            auto& visits = userEntry.second;
            sort(visits.begin(), visits.end()); // Sort by timestamp
            
            set<vector<string>> userTriplets;
            int n = visits.size();
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        userTriplets.insert({
                            visits[i].second,
                            visits[j].second,
                            visits[k].second
                        });
                    }
                }
            }
            
            for (const auto& triplet : userTriplets) {
                websiteCount[triplet]++;
            }
        }
        
        vector<string> res;
        int maxCount = 0;
        for (const auto& entry : websiteCount) {
            if (entry.second > maxCount || (entry.second == maxCount && entry.first < res)) {
                res = entry.first;
                maxCount = entry.second;
            }
        }
        
        return res;
    }
};