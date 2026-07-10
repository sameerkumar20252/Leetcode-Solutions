class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, j = 0;
        int n = pushed.size();

        while(i < n) {
            s.push(pushed[i]);
            while(s.size() > 0 && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            if(s.size() > 0 && i == n-1) {
                return false;
            }
            i++;
        }

        return true;
    }
};