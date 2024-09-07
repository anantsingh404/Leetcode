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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool ans=false;
bool dfs(ListNode * head,TreeNode *root)
{
    if(!head)
    {
        return true;
    }
    if(!root)
    {
        return false;
    }
    if(head->val!=root->val)
    {
        return false;
    }
  return dfs(head->next,root->left)|dfs(head->next,root->right);

}
void solve(ListNode * head,TreeNode *root)
{   
   
    if(!root)
    {
        return ;
    }
   if(head->val==root->val)
   {
    ans|=dfs(head,root);
   }
   
     solve(head,root->left);  
     solve(head,root->right);
    
    
   
    
    return ;

}
    bool isSubPath(ListNode* head, TreeNode* root) {
       solve(head,root); 
       return ans;
    }
};