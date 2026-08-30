class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long x, long long y) {
        long long ans = 1;
        while(y > 0) {
            if(y & 1) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }

        return ans;
    }
    
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;

        for(long long n : nums) {
            int width = n % 10;
            long long d = n / 10;

            string str = to_string(d);
            string strX = str.substr(0,width);
            string strY = str.substr(width);

            int x = stoi(strX);
            int y = stoi(strY);

            sum = (sum + power(x, y)) % MOD;
        }

        return sum;
    }
};