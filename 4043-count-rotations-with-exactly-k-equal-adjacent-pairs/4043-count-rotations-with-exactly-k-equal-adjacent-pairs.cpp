class Solution {
public:
    int countRotations(string s, int m) {
        int n = s.length();
        int ans = 0;

        for(int k = 0; k < n; k++) {
            int score = 0;
            for(int x = 0; x < n - 1; x++) {
                int i = (k + x) % n;
                if(s[i] == s[(i+1)%n]) {
                    score++;
                }
            }

            if(score == m) {
                ans++;
            }
        }

        return ans;
    }
};