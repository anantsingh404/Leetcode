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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * prev=NULL;
        ListNode * temp=NULL;
        ListNode * cur=head->next;
        while(cur)
        {    
           
            if(cur->val==0)
            {
                cur=cur->next;
            }
            else 
            {    int count=0;
                  if(!prev)
                  {
                    prev=cur;
                    temp=prev;
                  }
                  else
                  {
                    prev->next=cur;
                    prev=prev->next;
                  }
                while(cur && cur->val>0)
                {
                 count+=cur->val;
                 cur=cur->next;
                }
                prev->val=count;

            }
        }
    prev->next=NULL;
        return temp; 
    }
};