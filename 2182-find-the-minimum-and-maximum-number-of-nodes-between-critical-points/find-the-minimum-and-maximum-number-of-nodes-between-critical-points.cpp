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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int maxi=INT_MIN;
    int mini=INT_MAX;
     int i=0;
     int first=-1;
     int second=-1;
     int ans=-1;
      ListNode * prev=head;
      ListNode * cur=head->next;
      while(cur->next)
      {
        if(cur->val>prev->val && cur->val>cur->next->val)
        {   if(ans!=-1){
            //maxi=max(maxi,i-maxi);
            mini=min(mini,i-ans);
            ans=i;
        }
        if(ans=-1)
        {
            ans=i;
        }
        if(first==-1)
        {
            first=i;
        }
        second=i;
        }
        else if(cur->val<prev->val && cur->val<cur->next->val)
        {   if(ans!=-1){
           // maxi=max(maxi,cur->val);
            mini=min(mini,i-ans);
            ans=i;
        }
        if(ans==-1)
        {
            ans=i;
        }
        if(first==-1)
        {
            first=i;
        }
        second=i;
        }
        prev=cur;
        cur=cur->next;
        i++;
      }
      if(first==second)
      {
        return {-1,-1};
      }
      return {mini,second-first};
    }
};