class Solution {
    public int climbStairs(int n, int[] costs) {
        int a = costs[0] + 1;
        if(n == 1) return a;
        int b = costs[1] + 4;
        b = Math.min(b, a + costs[1] + 1);
        if(n == 2) return b;
        int c = Math.min(Math.min(costs[2] + 9, b + costs[2] + 1), a + costs[2] + 4);
        if(n == 3) return c;

        for(int i = 3; i < n; i++) {
            int temp = Math.min(a + costs[i] + 9, Math.min(b + costs[i] + 4, c + costs[i] + 1));
            a = b;
            b = c;
            c = temp;
        }

        return c;
    }
}