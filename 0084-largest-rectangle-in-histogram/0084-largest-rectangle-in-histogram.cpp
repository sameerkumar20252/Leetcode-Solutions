class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans=0;
        int n=h.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        stack<int> s;
        //right
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && h[s.top()]>=h[i]){
                s.pop();
            }
            right[i]=s.empty()?n:s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        //left
        for(int i=0;i<n;i++){
            while(s.size()>0 && h[s.top()]>=h[i]){
                s.pop();
            }
            left[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        for(int i=0;i<h.size();i++){
            int width = right[i]-left[i]-1;
            int currArea=h[i]*width;
            ans = max(currArea,ans);
        }
        return ans;
    }
};