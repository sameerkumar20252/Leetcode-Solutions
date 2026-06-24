class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        if(n==1) return h[0];
        stack<int> s;
        vector<int> L(n);
        vector<int> R(n);
        for(int i = 0; i < n; i++){
            while(s.size() > 0 && h[s.top()] >= h[i]){
                s.pop();
            }
            L[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i = n-1; i >= 0; i--){
            while(s.size() > 0 && h[s.top()] >= h[i]){
                s.pop();
            }
            R[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            int l,r;
            l = L[i]==-1 ? 0 : L[i]+1;
            r = R[i]==-1 ? n-1 : R[i]-1;
            int curr = (r-l+1)*h[i];
            ans = ans < curr ? curr : ans;
        }
        return ans;
    }
};