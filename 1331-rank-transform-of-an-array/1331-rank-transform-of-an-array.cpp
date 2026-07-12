class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) {
            return {};
        }
        vector<int> ans = arr;
        unordered_map<int, int> m;
        sort(arr.begin(), arr.end());

        int rank = 1;
        m[arr[0]] = 1;
        for(int i = 1; i < n; i++) {
            if(arr[i] != arr[i-1]) {
                rank++;
                m[arr[i]] = rank;
            }
        }

        for(int i = 0; i < n; i++) {
            ans[i] = m[ans[i]];
        }

        return ans;
    }
};