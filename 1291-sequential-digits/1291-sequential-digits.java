class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        String maxAns = "123456789";
        List<Integer> ans = new ArrayList<>();

        for(int i = 2; i <= 9; i++) {  //number of digit
            for(int j = 0; j <= 9 - i; j++) { //from where
                String str = maxAns.substring(j, j + i);
                Integer num = Integer.parseInt(str);

                if(num >= low && num <= high) {
                    ans.add(num);
                }
            }
        }

        return ans;
    }
}