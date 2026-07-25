class Solution {
public:
    int maxProduct(int n) {
        vector<int> freq(10, 0);

        while(n > 0) {
            int r = n % 10;
            freq[r]++;
            n /= 10;
        }

        int a = -1, b = -1;

        for(int i = 9; i >= 0; i--) {
            if(a == -1 && freq[i] > 1) {
                return i * i;
            }
            if(a == -1 && freq[i] > 0) {
                a = i;
                continue;
            }
            if(a != -1 && freq[i] > 0) {
                b = i;
                break;
            }
        }

        return a * b;
    }
};