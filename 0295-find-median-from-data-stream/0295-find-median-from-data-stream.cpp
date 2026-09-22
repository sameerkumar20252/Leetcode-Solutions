class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        n++;
        if(mx.size() == 0) {
            mx.push(num);
            return;
        }
        if(mn.size() < mx.size()) {
            if(num < mx.top()) {
                int val = mx.top();
                mx.pop();
                mx.push(num);
                mn.push(val);
            }else {
                mn.push(num);
            }
        } else {
            if(num > mn.top()) {
                int val = mn.top();
                mn.pop();
                mn.push(num);
                mx.push(val);
            } else {
                mx.push(num);
            }
        }
    }
    
    double findMedian() {
        int x = mx.top();
        int y;
        if(mn.size() > 0) y = mn.top();
        if(mx.size() == mn.size()) {
            double ans = ((x + y) * 1.0) / 2.0;
            return ans;
        }
        double ans = x * 1.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */