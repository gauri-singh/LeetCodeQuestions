class Twitter {
public:
struct compare{
    bool operator()(vector<int> a, vector<int> b){
        return a[0]<b[0];//maxheap
    }
};
int time=0;
unordered_map<int,unordered_set<int>> followmap;
unordered_map<int,vector<pair<int,int>>> tweetmap;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>,vector<vector<int>>,compare> maxheap;
        followmap[userId].insert(userId);
        for(auto followee : followmap[userId]){
            vector<pair<int,int>> tweets=tweetmap[followee];
            if(tweets.size()>0){
                int index=tweets.size()-1; // start from last of the list to get most recent.
                //time, tweetid, pointer for the current followee's tweet, current followeeid
                maxheap.push({tweets[index].first,tweets[index].second,index,followee});// adding most recent tweet of each followee including self
            }
        }
        vector<int> result;
        while(result.size()<10 && !maxheap.empty()){
            int tweetId = maxheap.top()[1]; // tweet id of current tweet
            int index = maxheap.top()[2]; // index of most recent tweet
            int userId = maxheap.top()[3]; //followee id
            maxheap.pop();
            result.push_back(tweetId);
            if(index>0){
                //next tweet id
                index--; // get next recent tweet (tweets inserted as a queue in the list )
                int tweetTime =tweetmap[userId][index].first;
                 tweetId = tweetmap[userId][index].second;
                maxheap.push({tweetTime,tweetId,index,userId});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */