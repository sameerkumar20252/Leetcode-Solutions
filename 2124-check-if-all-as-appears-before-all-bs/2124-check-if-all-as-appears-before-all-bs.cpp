class Solution {
public:
    bool checkString(string s) {
        int lastA = -1, firstB = 101;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'a') {
                lastA = i;
            } else {
                if(firstB == 101) {
                    firstB = i;
                }
            }
        }

        return lastA < firstB;
    }
};