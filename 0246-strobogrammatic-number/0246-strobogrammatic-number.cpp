class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> pairs ={{'1','1'},
                                        {'8','8'},
                                        {'6','9'},
                                        {'9','6'},
                                        {'0','0'}};
        int l=0,r=num.length()-1;
        while(l<=r){
            char left=num[l], right=num[r];
            if(!pairs.count(left) || pairs[left]!=right){
                return false;
            }
            l++; r--;
        }
        return true;
    }
};