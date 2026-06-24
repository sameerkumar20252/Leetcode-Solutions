class Solution {
public:
    int gcd(int a,int b){
        if(a==0){
            return b;
        }
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=pow(n,2);
        int sumEven=n*(n+1);
        return gcd(sumOdd,sumEven);
    }
};