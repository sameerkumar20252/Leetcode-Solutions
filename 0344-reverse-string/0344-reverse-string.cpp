class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0,end=s.size();
        while(start<end){
            swap(s[start],s[end-1]);
            start++;
            end--;
        }
    }
};