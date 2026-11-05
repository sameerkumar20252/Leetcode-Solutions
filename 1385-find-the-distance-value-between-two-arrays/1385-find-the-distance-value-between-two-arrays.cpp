class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        
        for(int x : arr1) {
            int st = 0, end = arr2.size() - 1;
            bool flag = false;
            while(st <= end) {
                int mid = st + (end - st)/2;
                int diff = abs(x - arr2[mid]);
                if(diff <= d) {
                    flag = true;
                    break;
                }
                if(x >= arr2[mid]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }

            if(!flag) ans++;
        }

        return ans;
    }
};