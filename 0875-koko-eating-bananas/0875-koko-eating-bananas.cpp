class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = INT_MIN;
        for(int x : piles) {
            mx = max(mx, x);
        }

        int l = 1, r = mx;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            long long totalTime = 0;
            for(int x : piles) {
                totalTime += (x / mid);
                int r = x % mid;
                if(r > 0) totalTime++;
            }

            if(totalTime > h) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};