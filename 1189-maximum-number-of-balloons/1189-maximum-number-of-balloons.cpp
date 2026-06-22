class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        vector<int> freq(26,0);
        for(char ch : text) {
            freq[ch - 'a']++;
        }

        freq[11] /= 2;
        freq[14] /= 2;

        for(int i = 0; i < 26; i++) {
            if(i == 0 || i == 1 || i == 11 || i == 13 || i == 14) {
                ans = min(ans, freq[i]);
            }
        }
        return ans;
    }
};