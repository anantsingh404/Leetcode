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
    public ListNode rotateRight(ListNode head, int k) {
     int count=0;
     ListNode x=head;
     ListNode last=null;
     if(head==null)
     {
        return null;
     }
     while(x!=null)
     {  if(x.next==null)
     {
        last=x;
     }
        x=x.next;
        ++count;
        
     } if(head==null || k==0 || k%count==0)
     {
        return head;
     }
     System.out.println(count);
     k=k%count;
     x=head;
     ListNode flag=null;
     ListNode flag1=null;
     int emp=count-k;
     while(emp>0 && x!=null)
     {
        flag=x;
        flag1=x.next;
        x=x.next;
        --emp;
     }
     flag.next=null;
     last.next=head;
     return flag1;

    }
}