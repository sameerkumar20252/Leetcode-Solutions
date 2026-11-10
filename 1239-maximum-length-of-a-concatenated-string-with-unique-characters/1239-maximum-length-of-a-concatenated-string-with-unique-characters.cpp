class Solution {
public:
    bool hasDuplicate(string& s1, string& s2) {
        bool arr[26] = {false};

        for(char& ch : s1) {
            if(arr[ch - 'a']) return true;
            arr[ch - 'a'] = true;
        }

        for(char& ch : s2) {
            if(arr[ch - 'a']) return true;
            arr[ch - 'a'] = true;
        }
        return false;
    }

    int helper(int i, vector<string>& arr, string temp, int n) {
        if(i >= n) return temp.length();

        int in = 0;
        int ex = 0;

        if(hasDuplicate(arr[i], temp)) {
            ex = helper(i+1, arr, temp, n);
        } else {
            ex = helper(i+1, arr, temp, n);
            in = helper(i+1, arr, temp + arr[i], n);
        }

        return max(in, ex);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        return helper(0, arr, temp, n);
    }
};