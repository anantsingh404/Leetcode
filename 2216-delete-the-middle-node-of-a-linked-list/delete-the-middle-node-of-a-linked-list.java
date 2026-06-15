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
    public ListNode deleteMiddle(ListNode head) {
       ListNode slow=head;
       ListNode fast=head;
       ListNode prev=head;
        ListNode next=null;
        if(head.next==null)
        {
            return null;
        }
       while(fast!=null && fast.next!=null)
       {
        prev=slow;
        slow=slow.next;
        next=slow.next;
        fast=fast.next.next;
       } 
       if(prev!=null){
       prev.next=next;
       }
       return head;

    }
}