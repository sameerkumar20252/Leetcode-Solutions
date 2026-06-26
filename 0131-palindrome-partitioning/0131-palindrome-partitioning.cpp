class Solution {
public:
    bool isPalindrome(string s){
        int st=0,end=s.length()-1;
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void getallPartition(string s,vector<string>& par,vector<vector<string>>& ans){
        if(s.length()==0){
            ans.push_back(par);
            return;
        }

        for(int i=0;i<s.length();i++){
            string part = s.substr(0,i+1);
            if(isPalindrome(part)){
                par.push_back(part);
                getallPartition(s.substr(i+1),par,ans);
                par.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> par;

        getallPartition(s,par,ans);
        return ans;
    }
};