class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowN = matrix.size(), colsN=matrix[0].size();
        int top=0, bot=rowN-1,midRow; //(top row and bottom row)
        while(top<=bot){
            midRow=(top+bot)/2;
            if(target>matrix[midRow][colsN-1]){
                //target is larger than last element of midRow, need to check next row onwards
                top=midRow+1;
            }
            else if(target<matrix[midRow][0]){
                //target is smaller than first element of midRow, need to above row onwards
                bot=midRow-1;
            }else{
                break;
            }
        }
        if(!(top<=bot)){
            //we didnt find target to match any of the row conditions:
            return false;
        }
        int l=0,r=colsN-1,mid;
          midRow=(top+bot)/2;
          //regular binary search in the selected row
        while(l<=r){
            mid=(l+r)/2;
            if(matrix[midRow][mid]>target){
                r=mid-1;
            }
            else if(matrix[midRow][mid]<target){
                l=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(auto vec:matrix){
//             bool res = binarySearch(vec,target);
//             if(res){
//                 return res;
//             }
//         }
//         return false;
//     }
//     bool binarySearch (vector<int> vec, int target){
//         int left=0, right = vec.size()-1 , mid;
//         while(left<=right){
//             mid=(left+right)/2;
//             if(vec[mid]>target){
//                 right=mid-1;
//             }
//             else if(vec[mid]<target){
//                 left=mid+1;
//             }
//             else{
//                 return true;
//             }
//         }
//         return false;
//     }
// };