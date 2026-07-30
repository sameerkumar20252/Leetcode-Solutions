class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end());
        int ans = 0;

        for(int i = 25; i >= 0; i--) {
            if(freq[i] == 0) {
                break;
            }
            int cost = (25 - i) / 8 + 1;
            ans += freq[i] * cost;
        }

        return ans;
    }
};