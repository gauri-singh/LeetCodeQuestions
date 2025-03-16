class MovingAverage {
public:
queue<int> q;
double sum=0;
int windowSize;
    MovingAverage(int size) {
        windowSize=size;
    }
    
    double next(int val) {
        sum+=val;
        q.push(val);
        if(q.size()>windowSize){
            sum-=q.front();q.pop();
        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */