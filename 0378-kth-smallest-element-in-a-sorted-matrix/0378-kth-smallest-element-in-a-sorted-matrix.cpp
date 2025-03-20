class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int lo =matrix[0][0];
        int hi=matrix[n-1][n-1];
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int count=getCount(matrix,mid);
            if(count>=k){
               //try to look for a smaller value in the left side
                ans=mid;
                hi=mid-1;
            }
            else {
               // try to look for a bigger value in the right side
                lo=mid+1;
            }
        }
        return ans;
    }
    int getCount(vector<vector<int>>& matrix, int num){
        int count=0;
        int n=matrix.size();
        int c=n-1;
        for(int r=0;r<n;r++){
            while(c>=0 && matrix[r][c]>num){
                c--; // if the current column has greater values than our number look to the left
            }
            count+=(c+1); // now we have reached the column which is the upper bound, so just add the number of columns to the left, since all numbers from 0->c will be less than our number now
            // repeat for all rows;
        }
        return count;
    }
//maxheap approach
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     priority_queue<int> maxheap;
    //     for(int i=0;i<matrix.size();i++){
    //         for(int j=0;j<matrix[0].size();j++){
    //             maxheap.push(matrix[i][j]);
    //             if(maxheap.size()>k){
    //                 maxheap.pop();
    //             }
    //         }
    //     }
    //     return maxheap.top();
    // }
};