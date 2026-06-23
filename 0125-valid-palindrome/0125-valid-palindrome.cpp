class Solution {
public:
    bool isAlphaNum(char c){
        if((c>='0'&&c<='9') || (tolower(c)>='a'&&tolower(c)<='z')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int st=0,end = s.length();
        while(st<end){
            if(!isAlphaNum(s[st])){
                st++;
                continue;
            }
            if(!isAlphaNum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }else{
                st++;
                end--;
            }
        }
        return true;
    }
};