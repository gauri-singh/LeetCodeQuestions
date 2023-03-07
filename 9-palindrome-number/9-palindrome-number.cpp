class Solution {
public:
    bool isPalindrome(int x) {
        // if(x<0)
        //     return false;
        // Way #1
        // int temp = x;
        // long rev=0;
        // while(temp>0){
        //     int d =temp%10;
        //     rev=rev*10+d;
        //     temp=temp/10;
        // }

        // return x == rev;

        // Way #2
        // long div=1;
        // while(x>=10*div){
        //     //we have to find the 10s multiple that would help us get the left most digit
        //     div*=10;
        // }
        // while(x>0){
        //     //getting digit from back
        //     int right= x%10;
        //     int left = x/div;
        //     if(left!= right){
        //         return false;
        //     }
        //     x=(x%div)/10;// will chop off left and right digits
        //     //basically
        //     //x= x%div --- to chop of right digit
        //     //x=x/10 ---- chop off left digit
        //     div= div/100;
        //     //since we chopped off two digits we can do this to decrease the diviser by 2 digits
        // }
        // return true;

        //Way 3
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int rev=0;
        while(x>rev){
            rev=rev*10+x%10;
           x = x/10;
        }
        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it
        return rev == x || x== rev/10;
        
    }
};