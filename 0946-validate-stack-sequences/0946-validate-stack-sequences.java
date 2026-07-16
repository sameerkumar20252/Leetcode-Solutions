class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int i = 0, j = 0;
        int n = pushed.length;

        for(int k  = 0; k < n; k++) {
            pushed[i] = pushed[k];
            i++;
            while(i > 0 && pushed[i-1] == popped[j]) {
                i--;
                j++;
            }
            if(i > 0 && k == n - 1) {
                return false;
            }
        }

        return true;
    }
}