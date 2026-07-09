class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n);

        int maxR = INT_MIN;
        for(int i = n - 1; i >= 0; i--) {
            right[i] = maxR;
            maxR = max(maxR, height[i]);
        }

        int left = INT_MIN;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(left != INT_MIN && right[i] != INT_MIN) {
                int x = min(left, right[i]);
                if(height[i] <= x) {
                    ans += x - height[i];
                }
            }
            left = max(left, height[i]);
        }

        return ans;
    }
};