class Solution {
public:
    int reverse(int x) {
        int newWord=0;
        while(x!=0){
            int r=x%10;
            if(newWord > INT_MAX/10 || newWord < INT_MIN/10){
                return 0;
            }
            newWord=newWord*10+r;
            x/=10;
        }
        return newWord;
    }
};