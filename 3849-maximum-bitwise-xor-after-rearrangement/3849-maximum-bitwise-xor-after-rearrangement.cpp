class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        int t1 = 0, t0 = 0;
        for(int i = 0; i < n; i++){
            if(t[i] == '0') t0++;
            else t1++;
        }
        
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(t1 > 0){
                    t[i] = '1';
                    t1--;
                }else{
                    t[i] = '0';
                    t0--;
                }
            }
            if(s[i] == '1'){
                if(t0 > 0){
                    t[i] = '0';
                    t0--;
                }else{
                    t[i] = '1';
                    t1--;
                }
            }
            if(s[i] != t[i]){
                s[i]= '1';
            }else {
                s[i]= '0';
            }
        }

        return s;
    }
};