class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;

        for(int i = n - 1; i >= 0; i--) {
            while(s.size() > 0 && h[s.top()] >= h[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && h[s.top()] >= h[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = width * h[i];
            ans = max(ans, area);
        }

        return ans;
    }
};