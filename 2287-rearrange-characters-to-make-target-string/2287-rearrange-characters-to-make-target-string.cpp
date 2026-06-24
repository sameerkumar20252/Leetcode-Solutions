class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        int ans = INT_MAX;

        for(char ch : target) {
            freq1[ch - 'a']++;
        }

        for(char ch : s) {
            freq2[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq1[i] > 0) {
                ans = min(ans, freq2[i]/freq1[i]);
            }
        }

        return ans;
    }
};