class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if(n > m) return "";

        unordered_map<char,int> need;
        unordered_map<char,int> window;
        int match = 0;
        int a = -1, b = -1;
        int len = INT_MAX;

        for(char ch : t) {
            need[ch]++;
        }

        int i = 0;
        for(int j = 0; j < m; j++) {
            if(need.count(s[j])) {
                window[s[j]]++;
                if(window[s[j]] == need[s[j]]) {
                    match++;
                }
            }
            bool valid = false;
            if(match == need.size()) {
                valid = true;
            }

            while(valid ) {
                if(len > (j - i + 1)) {
                    a = i; b = j;
                    len = (j - i + 1);
                }
                if(window.count(s[i])) {
                    window[s[i]]--;
                    if(window[s[i]] < need[s[i]]) {
                        match--;
                        valid = false;
                    }
                }
                i++;
            }
        }

        if(a == -1 || b == -1) return "";

        return s.substr(a, b-a+1);
    }
};