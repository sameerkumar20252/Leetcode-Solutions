class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = 0;
        const int limit = 1e9;

        for(int x : nums) {
            m[x]++;
        }

        if(m[1] % 2 != 0) {
            ans = max(ans, m[1]);
        } else {
            ans = max(ans,m[1]-1);
        }

        for(auto& a : m) {
            int x = a.first;
            if(x > 1 && x <= limit/x) {
                int p = (x * x);
                int len = 1;

                while(p <= limit && m.count(p) && m[x] > 1) {
                    len++;
                    x = p;
                    if (p > limit / p) break;
                    p = p*p;
                }
                len = 2 * len - 1;
                ans = max(ans,len);
            }
        }

        return ans;

    }
};