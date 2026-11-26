class Solution {
public:
    bool canAliceWin(int n) {
        int stone = 10;
        bool alice = false;

        while(stone <= n) {
            n -= stone;
            stone--;
            alice = alice ? false : true;
        }

        return alice;
    }
};