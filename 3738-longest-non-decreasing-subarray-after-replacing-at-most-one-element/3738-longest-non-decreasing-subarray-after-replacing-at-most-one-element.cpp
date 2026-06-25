// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int ans= INT_MIN;
//         int curr =0,temp=0;
//         bool flag = false;
//         for(int i =0;i<nums.size()-1;i++){
//             if(flag){
//                 if(nums[i]>=temp){
//                     ans++;
//                     continue;
//                 }else{
//                     curr = 0;
//                     if(nums[i]>=nums[i-1]){
//                         curr++;
//                     }else{
//                         curr++;
//                         if(curr>ans){
//                             ans=curr;
//                         }
//                     }
//                     i--;
//                 }
//                 flag = false;
//                 continue;
//             }
//             if(nums[i]<=nums[i+1]){
//                 curr++;
//             }else{
//                 temp = nums[i];
//                 curr++;
//                 i++;
//                 flag=true;
//             }
//             if(curr>ans){
//                 ans=curr;
//             }
//         }
//         curr++;
//         if(curr>ans){
//             ans=curr;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
          int n = nums.size();

        // Store the input midway as requested
        vector<int> serathion = nums;

        vector<int> left(n, 1), right(n, 1);

        for(int i = 1; i < n; i++){
            if(nums[i] >= nums[i-1])
                left[i] = left[i-1] + 1;
        }

        for(int i = n-2; i >= 0; i--){
            if(nums[i] <= nums[i+1])
                right[i] = right[i+1] + 1;
        }

        int ans = 1;

        // No replacement case (just existing streaks)
        for(int i = 0; i < n; i++)
            ans = max(ans, left[i]);

        // Try replacing each element
        for(int i = 0; i < n; i++){
            int best = 1;

            if(i > 0)
                best = max(best, left[i-1] + 1);

            if(i < n-1)
                best = max(best, right[i+1] + 1);

            if(i > 0 && i < n-1 && nums[i-1] <= nums[i+1])
                best = max(best, left[i-1] + 1 + right[i+1]);

            ans = max(ans, best);
        }

        return ans;
    }
};
