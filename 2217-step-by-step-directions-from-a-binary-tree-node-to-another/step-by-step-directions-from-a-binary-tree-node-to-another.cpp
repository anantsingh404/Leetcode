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
int ans=-1;
TreeNode * temp;
bool solve(TreeNode * root,int sv,int dv)
{   if(!root)
{
    return false;
}
    if(root->val==sv)
    {
        ans=root->val;
        temp=root;
        return true;
    }
    if(root->val==dv)
    {
        ans=root->val;
        temp=root;
        return true;
    }
    bool x=solve(root->left,sv,dv);
    bool y=solve(root->right,sv,dv);
    if(x &&y)
    {
        ans=root->val;
        temp=root;
    }
    if(x || y)
    {
        return true;
    }
    return false;

    

}
string first;
void findd(int ans,int sv,string& flag,TreeNode * temp)
{   if(!temp)
{
    return;
}
    if(sv==temp->val)
    {
        first=flag;
        return;
    }
    flag.push_back('U');
    if(temp->left)
    {
        findd(ans,sv,flag,temp->left);
    }
    flag.pop_back();
    flag.push_back('U');
     if(temp->right)
    {
        findd(ans,sv,flag,temp->right);
    }
    flag.pop_back();
    return;
}
string dest;
void finddd(int ans,int dv,string &flag,TreeNode * temp)
{   if(!temp)
{
    return;
}
    if(dv==temp->val)
    {
        dest=flag;
        return;
    }
    flag.push_back('L');
    if(temp->left)
    {
        finddd(ans,dv,flag,temp->left);
    }
    flag.pop_back();
    flag.push_back('R');
     if(temp->right)
    {
        finddd(ans,dv,flag,temp->right);
    }
    flag.pop_back();
    return;
}
    string getDirections(TreeNode* root, int sv, int dv) {
      solve(root,sv,dv);
      string z;
      findd(ans,sv,z,temp);
      z="";
      reverse(first.begin(),first.end());
      finddd(ans,dv,z,temp);
      return first+dest;
    }
};