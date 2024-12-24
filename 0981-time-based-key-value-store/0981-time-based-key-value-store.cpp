class TimeMap {
public:
    unordered_map <string,vector<pair<string,int>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        //vector<pair<string,int>> vec;
        string result="";
        if(map.count(key)){
           auto& vec=map[key];
            int l=0,r=vec.size()-1,mid;
            while(l<=r){
                mid=l+(r-l)/2;
                if(vec[mid].second<=timestamp){
                    //exact match or nearest time which is less than timestamp
                    result=vec[mid].first;
                    l=mid+1;
                }else{
                    r=mid-1; //move towards left side to find a smaller timestamp
                }
            }
        }
        return result;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */