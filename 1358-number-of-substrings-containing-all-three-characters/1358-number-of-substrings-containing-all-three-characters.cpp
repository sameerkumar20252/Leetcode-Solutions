class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int i = 0, n = s.length();
        vector<int> freq(3, 0);

        for(int j = 0; j < n; j++) {
            freq[s[j] - 'a']++;

            while(freq[0] && freq[1] && freq[2]) {
                ans += (n - j);
                freq[s[i] - 'a']--;
                i++;
            }
        }

        return ans;
    }
};