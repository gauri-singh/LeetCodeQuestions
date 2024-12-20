class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto vec:matrix){
            bool res = binarySearch(vec,target);
            if(res){
                return res;
            }
        }
        return false;
    }
    bool binarySearch (vector<int> vec, int target){
        int left=0, right = vec.size()-1 , mid;
        while(left<=right){
            mid=(left+right)/2;
            if(vec[mid]>target){
                right=mid-1;
            }
            else if(vec[mid]<target){
                left=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
