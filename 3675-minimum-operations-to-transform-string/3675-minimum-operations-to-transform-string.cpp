class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        char mn = 'z' + 1;
        for(char ch : s) {
            if(ch != 'a') {
                if(ch < mn) {
                    mn = ch;
                }
            }
        }

        if(mn == 'z' + 1) return ans;
        ans = 'z' - mn + 1;
        return ans;
    }
};