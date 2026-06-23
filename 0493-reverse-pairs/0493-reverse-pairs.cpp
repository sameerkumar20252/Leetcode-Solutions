class Solution {
public:
    int ans = 0;

    void merge(vector<int>& nums, int st, int mid, int end) {
        vector<int> temp(end - st + 1);
        int i = st, j = mid+1;
        int k = 0;

        int a = st, b = mid+1;
        while(a <= mid && b <= end) {
            if(nums[a] > 2 * (long)nums[b]) {
                ans += (mid - a + 1);
                b++;
            }
            else {
                a++;
            }
        }

        while(b <= end) {
            if(nums[mid] > 2 * (long)nums[b++]) {
                ans++;
            }
        }

        while(i <= mid && j <= end) {
            if(nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid) {
            temp[k++] = nums[i++];
        }

        while(j <= end) {
            temp[k++] = nums[j++];
        }

        for(int i = 0; i< temp.size(); i++) {
            nums[st + i] = temp[i];
        }
    }

    void divide(vector<int>& nums, int st, int end) {
        if(st < end) {
            int mid = st + (end - st)/2;
            divide(nums, st, mid);
            divide(nums, mid+1, end);

            merge(nums, st, mid, end);
        }
    }

    int reversePairs(vector<int>& nums) {
        divide(nums, 0, nums.size()-1);

        return ans;
    }
};