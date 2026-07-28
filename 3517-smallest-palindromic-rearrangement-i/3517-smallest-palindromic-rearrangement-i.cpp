class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int n = s.length();
        int i = 0, j = s.length() - 1;
        for(int k = 0; k < 26; k++) {
            if(i > j) break;
            int frq = freq[k];
            while(frq > 1) {
                s[i] = (char)('a' + k);
                s[j] = (char)('a' + k);
                i++; j--;
                frq = frq - 2;
            }
            if(frq == 1) {
                s[n/2] = (char)('a' + k);
            }
        }

        return s;
    }
};