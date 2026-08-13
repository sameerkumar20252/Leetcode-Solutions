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
    public ListNode partition(ListNode head, int x) {
        ListNode newHead = null;
        ListNode firstLarge = null;
        ListNode small = null;
        ListNode greater = null;

        while(head != null) {
            if(head.val < x) {
                if(newHead == null) {
                    newHead = head;
                }
                if(small != null) {
                    small.next = head;
                }
                small = head;
            } else {
                if(firstLarge == null) {
                    firstLarge = head;
                }
                if(greater != null) {
                    greater.next = head;
                }
                greater = head;
            }
            head = head.next;
        }

        if(small != null)
        small.next = firstLarge;
        if(greater != null)
        greater.next = null;

        if(newHead == null) {
            newHead = firstLarge;
        }

        return newHead;
    }
}