class Solution {
public:
    int minOperations(string s) {
        char mn = 'z' + 1;
        for(char ch : s) {
            if(ch != 'a') {
                if(ch < mn) {
                    mn = ch;
                }
            }
        }

        if(mn == 'z' + 1) return 0;
        return 'z' - mn + 1;
    }
};