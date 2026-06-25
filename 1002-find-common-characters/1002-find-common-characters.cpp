class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<string> ans2;
        unordered_map<char,int> m;
        int maxAns=INT_MAX;
        string xyz="";
        for(auto str: words){
            if(str.length()<maxAns){
                maxAns=str.length();
               xyz=str;
            }
        }
        for(int i=0;i<xyz.length();i++){
            ans.push_back(string(1, xyz[i]));
        }
        for(auto str: words){
            if(str!=xyz){
               for(int i=0;i<str.length();i++){
                   m[str[i]]++;
                }
                ans2=ans;
                for(int i=0;i<ans2.size();i++){
                    if(m.find(ans2[i][0])!=m.end() && m[ans2[i][0]]>0){
                        m[ans2[i][0]]--;
                    }else{
                         auto it = find(ans.begin(), ans.end(), ans2[i]);
                            if (it != ans.end()) {
                               ans.erase(it);
                                 }
                    }
                }
                m.clear();
            }
        }
    return ans;
    }
};