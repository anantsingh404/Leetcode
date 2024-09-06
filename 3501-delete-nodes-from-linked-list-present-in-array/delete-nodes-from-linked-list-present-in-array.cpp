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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        unordered_map<int,int>mp;
        ListNode * tmp=NULL;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        ListNode * prev=NULL;
        ListNode * cur=head;
        while(cur)
        {
            if(mp[cur->val]>0)
            {
                cur=cur->next;
            }
            else
            {
                if(prev)
                {
                    prev->next=cur;
                    cur=cur->next;
                    prev=prev->next;
                }
                else
                {   
                    tmp=cur;
                    prev=cur;
                    cur=cur->next;
                }
            }
        }
        prev->next=nullptr;
        return tmp;
        
    }
};