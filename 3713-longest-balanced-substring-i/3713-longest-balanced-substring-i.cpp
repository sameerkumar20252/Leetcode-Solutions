class Solution {
public:
    int longestBalanced(string s) {
        unordered_map<char,int> m;
        int n = s.length();
        int ans = 1;
        for(int i = 0; i < n; i++){
            m.clear();
            for(int j = i; j < n; j++){
                m[s[j]]++;
                bool allSame = true;

                int firstValue = m.begin()->second;
                for (auto &p : m) {
                    if (p.second != firstValue) {
                        allSame = false;
                        break;
                    }
                }

                if(allSame){
                    ans = ans < (j-i+1) ? j-i+1 : ans;
                }
            }
        }

        return ans;
    }
};