class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int> prefix(len,1);
        vector<int> postfix(len,1);
        vector<int> res(len,1);
        
        for(int i=1;i<len;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int j=len-2;j>=0;j--){
            postfix[j]=postfix[j+1]*nums[j+1];
        }
        for(int i=0;i<len;i++){
            res[i]=prefix[i]*postfix[i];
        }
        return res;
    
    }
};