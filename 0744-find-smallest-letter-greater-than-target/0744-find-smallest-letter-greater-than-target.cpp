class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if(target >= letters[n-1]){
            return letters[0];
        }
        if(target < letters[0]){
            return letters[0];
        }
        int st = 0, end = n - 1, mid = 0;
        char ans;
        while(st <= end){
            mid = st + (end - st)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                end = mid -1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};