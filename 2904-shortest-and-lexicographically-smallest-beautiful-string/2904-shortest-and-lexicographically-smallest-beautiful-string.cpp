class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i = 0;
        int n = s.length();
        int count = 0;
        int l = -1, r = -1;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') {
                count++;
            }
            if(count == k) {
                if(l == -1) {
                    l = i;
                    r = j;
                } else {
                    if((r - l + 1) > (j - i + 1)) {
                        l = i;
                        r = j;
                    } else if((r - l + 1) == (j - i + 1)) {
                        int len = r - l + 1;
                        for(int p = 0; p < len; p++) {
                            if(s[l + p] > s[i + p]) {
                                l = i;
                                r = j;
                                break;
                            }
                            if(s[i + p] > s[l + p]) {
                                break;
                            }
                        }
                    }
                }

                while(count >= k) {
                    if(s[i] == '1') {
                        count--;
                    }
                    if(l == -1) {
                    l = i;
                    r = j;
                } else {
                    if((r - l + 1) > (j - i + 1)) {
                        l = i;
                        r = j;
                    } else if((r - l + 1) == (j - i + 1)) {
                        int len = r - l + 1;
                        for(int p = 0; p < len; p++) {
                            if(s[l + p] > s[i + p]) {
                                l = i;
                                r = j;
                                break;
                            }
                            if(s[i + p] > s[l + p]) {
                                break;
                            }
                        }
                    }
                }
                i++;
                }
            }
        }

        if(l == -1) return "";

        return s.substr(l, r - l + 1);
    }
};