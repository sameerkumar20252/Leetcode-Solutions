class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int tr = target[0], tc = target[1];
        int r = source[0], c = source[1];
        if(abs(r - tr) == abs(c - tc)) {
            return 1;
        }
        //top-left
        while(r > 0 && c > 0) {
            if(abs(r - tr) == abs(c - tc)) {
                return 2;
            }
            r--, c--;
        }

        r = source[0], c = source[1];
        //top-right
        while(r > 0 && c < 8) {
            if(abs(r - tr) == abs(c - tc)) {
                return 2;
            }
            r--, c++;
        }

        //bottom-left
        r = source[0], c = source[1];
        while(r < 8 && c > 0) {
            if(abs(r - tr) == abs(c - tc)) {
                return 2;
            }
            r++, c--;
        }

        r = source[0], c = source[1];
        //bottom-right
        while(r < 8 && c < 8) {
            if(abs(r - tr) == abs(c - tc)) {
                return 2;
            }
            r++, c++;
        }

        return -1;
    }
};