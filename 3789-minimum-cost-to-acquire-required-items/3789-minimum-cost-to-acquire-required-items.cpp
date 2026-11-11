class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mxNeed = max(need1, need2);
        long long mnNeed = min(need1, need2);

        long long both = mxNeed * costBoth;

        long long single = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long mixed = mnNeed * costBoth + 1LL * (need1 - mnNeed) * cost1
                                            + 1LL * (need2 - mnNeed) * cost2; 

        return min({single, both, mixed});
    }
};