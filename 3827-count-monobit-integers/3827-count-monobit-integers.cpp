class Solution {
public:
    int countMonobit(int n) {
        if(n == 0) return 1;
        int bit = log2(n) + 1;
        if(pow(2,bit)-1 != n){
            return bit;
        }
        return ++bit;
    }
};