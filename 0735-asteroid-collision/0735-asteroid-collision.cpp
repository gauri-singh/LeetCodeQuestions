class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        // positive asteroid and then negative asteroid have collision
        //negative nd then positive dont have cause they both are going towards opposite directions
        for(auto asteroid: asteroids){
           while(!stk.empty() && asteroid*stk.top()<0){

            if(asteroid>0 && stk.top()<0){
                //they are moving in opposite directions
                break;
            }
            //stack has elements and the top and current asteroid is of diffferent signs
            int topAsteroid=stk.top();
            stk.pop();
            // this means that the new asteroid is coming from opposite direction
            if(abs(asteroid)==abs(topAsteroid)){
                asteroid=-9999;
                break;
                // both have collided and nothing is left
            }
            if (asteroid<0 && topAsteroid>0){
                //collision will happen
               asteroid = abs(asteroid)>abs(topAsteroid)? asteroid : topAsteroid;
               // we will push this value to stack , we choose the bigger value to be pushed
            }
           }
           if(asteroid!=-9999)
            stk.push(asteroid);
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
         reverse(res.begin(),res.end());
         return res;
    }
};