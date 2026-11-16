class Solution {
    public String digitSum(String s, int k) {
        int n;
        int count = 0;
        int num = 0;
        StringBuilder s2 = new StringBuilder();
        
        while(s.length() > k) {
            n = s.length();
            for(int i = 0; i < n; i++) {
                num += (s.charAt(i) - '0');
                count++;
                if(count == k) {
                    count = 0;
                    s2.append(String.valueOf(num));
                    num = 0;
                }
            }
            if(count > 0) s2.append(String.valueOf(num));
            count = 0;
            num = 0;
            s = s2.toString();
            s2.setLength(0);
        }

        return s;
    }
}