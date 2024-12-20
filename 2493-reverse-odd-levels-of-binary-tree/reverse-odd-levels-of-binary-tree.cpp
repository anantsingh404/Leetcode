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
    TreeNode* reverseOddLevels(TreeNode* root) {
     int i=0;
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty())
     {
        int n=q.size();
        vector<TreeNode*>vp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            TreeNode *x=q.front();
            if(x->left)
            {
                q.push(x->left);
                ans.push_back(x->left->val);
                vp.push_back(x->left);
            
            }
            if(x->right)
            {
                q.push(x->right);
                ans.push_back(x->right->val);
                vp.push_back(x->right);
            }
           
            q.pop();
            

        }
         if(i%2==0)
            {
                reverse(ans.begin(),ans.end());
                for(int i=0;i<vp.size();i++)
                {
                    vp[i]->val=ans[i];
                }
            }
        i++;
     } 
     return root;  
    }
};