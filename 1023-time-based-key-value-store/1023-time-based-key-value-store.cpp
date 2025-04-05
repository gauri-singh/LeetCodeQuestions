class TimeMap {
public:
    unordered_map <string,vector<pair<string,int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if (!map.count(key)) return "";

        auto& vec = map[key];
        int l = 0, r = vec.size() - 1;
        int ans = r + 1;

        // last occurrence where vec[i].second <= timestamp
        //upperbound 
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (timestamp<vec[mid].second ) {
                ans = mid;      // this is first failing index
                r = mid - 1;    // look left
            } else {
                l = mid + 1;    // this mid works, try later one
            }
        }

        int lastValid = ans - 1;// upperbound-1
        return (lastValid >= 0) ? vec[lastValid].first : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */