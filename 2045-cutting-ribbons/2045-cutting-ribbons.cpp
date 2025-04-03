class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        //our search range is from min size of ribbon: 1 and max size: biggest ribbon 
        int l=1, r=*max_element(ribbons.begin(),ribbons.end());
        int ans=r+1;// doesn't exist
        //since we want the maximum value i.e, last satisfying occurence 
        // or upperbound-1
        while(l<=r){
            int midLen=l+(r-l)/2;
            int numOfRibbons=getNumOfRibbons(ribbons,midLen);
            //we got too many ribbons of this size, we need to increase the ribbon size, here there is direct propotion
            if(numOfRibbons<k){
                ans=midLen;
                r=midLen-1;// look for shorter length ribbons
            }
            else{
                l=midLen+1;// look for larger length ribbons
            }
        }
        return ans-1;// last occurence 
    }
    int getNumOfRibbons(vector<int>& ribbons,int size){
        int count=0;
        for(auto r: ribbons){
            if(r-size>=0){
                count+=r/size;
            }
        }
        return count;
    }
};