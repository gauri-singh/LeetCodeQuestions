class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // at every index i, number of missing numbers = arr[i]-i-1 => eg if 11 is on index 5, that means we have 11-5-1=5 missing numbers
        int l=0, r=arr.size()-1;
        int ans=r+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int diff=(arr[mid]-mid-1);
            if(k<=diff){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        // At the end of the loop, left = right + 1,
        // and the kth missing is in-between arr[right] and arr[left].
        // The number of integers missing before arr[right] is
        // arr[right] - right - 1 -->
        // the number to return is
        // arr[right] + k - (arr[right] - right - 1) = k + left
        return k+l;
    }
};