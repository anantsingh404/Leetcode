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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++)
       {
        mp[nums[i]]++;
       } 
       ListNode * prev=NULL;
       ListNode * cur=head;
       while(cur)
       {
        if(mp[cur->val])
        {
            cur=cur->next;
        }
        else
        {   if(!prev)
        {
            prev=cur;
            head=prev;
        }
        else{
            prev->next=cur;
            prev=prev->next;
        }
            cur=cur->next;
        }
       }
       prev->next=NULL;
       return head;
    }
};