class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string &str : tokens){
            if(str!="+" && str!="-" && str!="*" && str!="/"){
                s.push(stoi(str));
            }else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(str == "+"){
                    s.push(a+b);
                }else if(str == "-"){
                    s.push(a-b);
                }else if(str == "*"){
                    s.push(a*b);
                }else{
                    s.push(a/b);
                }
            }
        }   
        return s.top();
    }
};