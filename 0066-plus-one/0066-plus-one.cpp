class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum=1, val=0, carry=0;
        for(int i=digits.size()-1;i>=0;i--){
            sum=sum+digits[i]+carry;
            val=sum%10;
            digits[i]=val;
            carry=sum/10;
            sum=0;
        }
        if(carry>0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};