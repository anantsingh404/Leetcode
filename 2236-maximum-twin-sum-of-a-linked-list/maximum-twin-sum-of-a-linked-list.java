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
    public int pairSum(ListNode head) {
     int count=0;
     ListNode x=head;
     int xx=0;
     while(x!=null)
     {
        x=x.next;
        ++xx;
     }
     x=head;
     ListNode y=head;
     xx=xx/2;
     int pp=xx;
     while(xx>0)
     { 
        y=y.next;
        --xx;
        
     } 
     ListNode prev=null;
     ListNode cur=y;
     //ListNode next=y;

     while(cur!=null){
        ListNode temp=cur.next;
        cur.next=prev;
        prev=cur;
        cur=temp;
     }


     while(pp>0)
     {
        count=Math.max(count,x.val+prev.val);
        x=x.next;
        prev=prev.next;
        --pp;
     }
      return count;
    }
}