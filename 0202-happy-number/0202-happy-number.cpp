class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(n!=1){
            if(st.contains(n)){
                return false;
            }
            st.insert(n);
            int temp=n;
            n=0;
            while(temp>0){
                int digit=temp%10;
                temp=temp/10;
                n+=digit*digit;
            }
        }
        return true;
    }
};