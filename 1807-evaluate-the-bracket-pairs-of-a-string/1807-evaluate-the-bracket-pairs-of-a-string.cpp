class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto& p : knowledge) {
            m[p[0]] = p[1];
        }

        bool flag = false;

        string str = "";
        string ans = "";
        for(char ch : s) {
            if(ch == '(') {
                str = "";
                flag = true;
            }
            else if(ch == ')') {
                flag = false;
                if(m.count(str)) {
                    ans += m[str];
                } else {
                    ans.push_back('?');
                }
                continue;
            }
            else if(flag) {
                str += ch;
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};