class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int idx = l;
        int p = nums[idx];
        l++;
        while(l <= r) {
            if(nums[l] < p && nums[r] > p) {
                swap(nums[l], nums[r]);
                l++, r--;
            }
            if(nums[l] >= p) {
                l++;
            }
            if(nums[r] <= p) {
                r--;
            }
        }
        swap(nums[r], nums[idx]);
        return r;
    }

    int quick_select(vector<int>& nums, int l, int r, int k) {
        int pivot = partition(nums, l, r);
        if(pivot == k - 1) {
            return nums[pivot];
        } else if(pivot > k - 1) {
            return quick_select(nums, l, pivot-1, k);
        } else {
            return quick_select(nums, pivot+1, r, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        return quick_select(nums, l, r, k);
    }
};