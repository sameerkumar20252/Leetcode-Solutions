class Solution {
public:
    int dig(int n) {
        string s = to_string(n);
        return s.length();
    }
    void convert(int n,string &ans){
        if(n==0){
            return;
        }
        if(n==4 || n==9 || n==40 || n==90 || n==400 ||n==900){
           if(n==400){
              ans="CD"+ans;
              return;
           }else if(n==900){
              ans = "CM"+ans;
              return;
           }else if(n==40){
              ans = "XL"+ans;
              return;
           }else if(n==90){
              ans = "XC"+ans;
              return;
           }else if(n==4){
              ans="IV"+ans;
              return;
           }else{
              ans = "IX"+ans;
              return;
           }
        }else{
           if(dig(n)==1){
              if(n<4){
                convert(n-1,ans);
                ans="I"+ans;
                return;
              }else{
                convert(n-5,ans);
                ans="V"+ans;
                return;
              }
            }else if(dig(n)==2){
                if(n<50){
                    convert(n-10,ans);
                    ans="X"+ans;
                    return;
                }else{
                    convert(n-50,ans);
                    ans="L"+ans;
                    return;
                }
            }else if(dig(n)==3){
                if(n<500){
                    convert(n-100,ans);
                    ans="C"+ans;
                    return;
                }else{
                    convert(n-500,ans);
                    ans="D"+ans;
                    return;
                }
            }else{
                convert(n-1000,ans);
                ans="M"+ans;
                return;
            }
        }
    }
    string intToRoman(int num) {
        string ans="";
        int p = 0;
        while(num!=0){
            int r = num%10;
            int x = r*pow(10,p);
            convert(x,ans);
            p++;
            num=num/10;
        }
        return ans;
    }
};