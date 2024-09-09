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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
      --m;
      --n;
      int i=0;
      int j=0;
      while(i<=m && j<=n)
      {
        for(int k=j;k<=n;k++)
        {
           dp[i][k]=head->val;
           head=head->next;
           if(!head)
           {
            return dp;
           }
        }
        i++;
        for(int k=i;k<=m;k++)
        {
            dp[k][n]=head->val;
            head=head->next;
             if(!head)
           {
            return dp;
           }
        }
        --n;
        for(int k=n;k>=j;k--)
        {
            dp[m][k]=head->val;
            head=head->next;
             if(!head)
           {
            return dp;
           }

        }
        --m;
        for(int k=m;k>=i;k--)
        {
            dp[k][j]=head->val;
            head=head->next;
             if(!head)
           {
            return dp;
           }
        }
        ++j;
      }
      return dp;

    }
};