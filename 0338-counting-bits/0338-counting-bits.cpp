class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 0; i <= n; i++) {
            int c1 = 0;
            int num = i;
            while(num > 0) {
                num % 2 ? c1++ : c1;
                num /= 2;
            }
            ans[i] = c1;
        }

        return ans;
    }
};