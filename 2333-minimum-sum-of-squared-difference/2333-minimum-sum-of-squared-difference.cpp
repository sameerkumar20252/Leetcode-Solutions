class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        vector<long long> diff(100001, 0);

        for(int i = 0; i < n; i++) {
            diff[abs(nums1[i] - nums2[i])]++;
        }

        for(int i = 100000; i >= 1 && k > 0; i--) {
            if(diff[i]) {
                long long countOpp = min(diff[i], k);
                diff[i] -= countOpp;
                diff[i - 1] += countOpp;
                k -= countOpp;
            }
        }

        long long ans = 0;

        for(int i = 0; i < 100001; i++) {
            if(diff[i] > 0) {
                ans += ((long long)i * i * diff[i]);
            }
        }

        return ans;
    }
};