class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = *min_element(nums1.begin(), nums1.end());

        int odd = 0, even = 0;
        for(int x : nums1) {
            if(x % 2 == 0) even++;
            else odd++;
        }

        if(minVal % 2 == 1) {
            return true;
        } else {
            return odd == 0;
        }
    }
};