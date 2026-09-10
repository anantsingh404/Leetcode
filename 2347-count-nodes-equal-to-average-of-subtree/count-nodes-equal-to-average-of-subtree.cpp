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
int ans;
pair<int,int> solve(TreeNode * root)
{
    if(!root)
    {
        return {0,0};
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    int nodecount=1+left.first+right.first;
    int val=root->val+left.second+right.second;
    if(val/nodecount==root->val)
    {
        ++ans;
    }
    return {nodecount,val};
}
    int averageOfSubtree(TreeNode* root) {ans=0;
    solve(root);
    return ans;
        
    }
};