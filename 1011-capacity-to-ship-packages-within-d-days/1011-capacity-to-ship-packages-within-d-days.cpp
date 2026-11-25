class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // l = 1, r = sum of all elements
        int sum = 0;
        int mx = INT_MIN;
        for(int x : weights) {
            mx = max(mx, x);
            sum += x;
        }

        int l = mx, r = sum;
        while(l <= r) {
            int mid = l + (r - l)/2;
            int day = 1;
            int load = 0;
            for(int x : weights) {
                if(load + x > mid) {
                    day++;
                    load = x;
                } else {
                    load += x;
                }
            }

            if(day > days) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};