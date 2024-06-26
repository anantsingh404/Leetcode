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
 vector<int>dp;
void solve(TreeNode * root)
{
    if(!root)
    {
        return;
    }
    solve(root->left);
    dp.push_back(root->val);
    solve(root->right);
}
TreeNode * build(int s,int e)
{
   if(s>e)
   {
    return NULL;
   }
   int mid=(s+e)/2;
   TreeNode * flag=new TreeNode(dp[mid]);
   flag->left=build(s,mid-1);
   flag->right=build(mid+1,e);
   return flag;
}
    TreeNode* balanceBST(TreeNode* root) {
      
       solve(root); 
       return build(0,dp.size()-1);
    }
};