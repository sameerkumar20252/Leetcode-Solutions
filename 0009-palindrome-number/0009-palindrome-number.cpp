class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int num = x;
        long long int r, revNum=0;
        while(x!=0){
            r = x%10;
            revNum = 10 * revNum + r;
            x/=10;
        }
        if(num == revNum){
            return true;
        }
        return false;
    }
};