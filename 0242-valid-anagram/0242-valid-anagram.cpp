class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        for(char ch:t){
            if(m.find(ch)==m.end() || m[ch]==0){
                return false;
            }else{
                m[ch]--;
            }
        }
    return true;
    }
};