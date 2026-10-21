class Solution {
public:
    int minOperations(string s) {
        if(s.length() == 2 && s[0] > s[1]) {
            return -1;
        } 
        int n = s.length();
        char mn = 'z';
        char mx = 'a';
        int count = 0;
        char prev = s[0];

        for(char ch : s) {
            mn = min(mn, ch);
            mx = max(mx, ch);
            if(prev > ch) count++;
            prev = ch;
        }

        if(count == 0) return 0;


        if(mn == s[0] && mx != s.back()
          || mn != s[0] && mx == s.back()
          || mn == s[0] && mx == s.back()) {
            return 1;
        }

        int mnIdx = -1, mxIdx = -1;
        for(int i = 0; i < s.length(); i++) {
            if(mnIdx == -1 && s[i] == mn) mnIdx = i;
            if(s[i] == mx) mxIdx = i;
        }

        if(mnIdx == n - 1 && mxIdx == 0) return 3;

        return 2;
    }
};