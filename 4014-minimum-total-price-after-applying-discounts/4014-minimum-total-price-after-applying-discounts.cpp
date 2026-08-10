class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int p = prices.size() - 1;
        int d = discounts.size() - 1;
        double ans = 0.0;

        while(p >= 0 && d >= 0) {
            double price = ((prices[p] * 1LL * (100 - discounts[d])) * 1.0) / 100;
            ans += price;
            p--; d--;
        }

        while(p >= 0) {
            ans += prices[p];
            p--;
        }

        return ans;
    }
};