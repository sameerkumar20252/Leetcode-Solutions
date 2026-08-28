/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int x : nums) {
            s.add(x);
        }

        int count = 0;
        int ans = 0;
        ListNode temp = head;

        while(temp != null) {
            if(s.contains(temp.val)) {
                count = 1;
            } else {
                ans += count;
                count = 0;
            }
            temp = temp.next;
        }

        ans += count;

        return ans;
    }
}