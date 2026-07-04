class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int m = target.size();
        int a = 1;


        for(int i = 0; i < m; i++) {
            ans.push_back("Push");
            if(target[i] != a) {
                ans.push_back("Pop");
                i--;
            }
            a++;
        }

        return ans;
    }
};