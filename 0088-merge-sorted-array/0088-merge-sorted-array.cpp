class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            for(int i=0;i<n;i++){
                nums1[i]=nums2[i];
            }
            return;
        }
        int i1=m-1,i2=n-1,k=m+n-1;
        //i1 is pointer for array 1 starting from end of values in array 1
        //k is end of the actual array 1 ( since towards the end it is filled with zeroes)
        while(i1>=0 && i2>=0){
            if(nums2[i2]>nums1[i1]){
                nums1[k]=nums2[i2];
                i2--;
            }else{
                nums1[k]=nums1[i1];
                i1--;
            }
            k--;
        }
        //fill nums1 with the left over numbers in nums2
        while(i2>=0){
            nums1[k]=nums2[i2];
            i2--;k--;
        }
    }
};