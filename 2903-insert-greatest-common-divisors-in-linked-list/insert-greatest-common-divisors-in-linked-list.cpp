/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
       if(!head->next)
       {
        return head;
       } 
       ListNode * prev=head;
       ListNode * cur=head->next;
       while(prev->next)
       {
        ListNode * x =new ListNode(__gcd(prev->val,cur->val));
        prev->next=x;
        x->next=cur;
        prev=cur;
        cur=cur->next;

       }
       return head;
    }
};