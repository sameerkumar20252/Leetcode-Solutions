class Solution {
public:
    static bool customCompare(const string& a, const string& b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), customCompare);
        return nums[nums.size()-k];
    }
};