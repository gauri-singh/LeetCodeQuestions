class MedianFinder {
public:
priority_queue<int> small; //maxheap
priority_queue<int,vector<int>,greater<int>> large;//maxheap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        if(!large.empty() && small.top()>large.top()){
            //largest element in small group is larger than smallest element in large group
            //need to rebalance and transfer it to large
            large.push(small.top());
            small.pop();
        }
        if(small.size()>large.size()+1){
            //dont use small-large>1 it causes negative int overflow
            large.push(small.top());
            small.pop();
        } else if(large.size()>small.size()+1){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(large.size()==small.size()){
            return (small.top()+large.top())/2.0;
        }
        else if(large.size()>small.size()){
            return large.top();
        }
        else if(small.size()>large.size()){
            return small.top();
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */