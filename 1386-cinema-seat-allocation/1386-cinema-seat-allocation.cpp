class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
        unordered_map<int, tuple<bool,bool,bool>> m;

        for(auto& row : v) {
            int r = row[0];
            int s = row[1];

            if (s >= 2 && s <= 5)
                get<0>(m[r]) = true;

            if (s >= 4 && s <= 7)
                get<1>(m[r]) = true;

            if (s >= 6 && s <= 9)
                get<2>(m[r]) = true;
        }
        int ans = (n - m.size()) * 2;

        for(const auto& [r, p] : m) {
            if(!get<0>(p) && !get<2>(p)) {
                ans += 2;
            } else if(!get<0>(p) || !get<1>(p) || !get<2>(p)) {
                ans += 1;
            }
        }

        return ans;
    }
};