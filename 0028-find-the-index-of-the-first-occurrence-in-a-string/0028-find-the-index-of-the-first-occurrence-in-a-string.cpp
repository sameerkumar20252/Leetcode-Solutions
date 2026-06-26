class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()>haystack.length()){
            return -1;
        }
        int len=needle.length();
        for(int i=0;i<=haystack.length()-len;i++){
            if(haystack.substr(i,len)==needle){
                return i;
            }else{
                continue;
            }
        }
        return -1;
    }
};