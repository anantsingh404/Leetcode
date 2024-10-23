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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=q.front()->val;
                 if(q.front()->left)
            {
                q.push(q.front()->left);
            }
             if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
            }
           
            ans.push_back(sum);
        }
        queue<TreeNode * >pq;
        pq.push(root);
        root->val=0;
        int i=1;
        while(!pq.empty())
        {
          int n=pq.size();
          for(int j=0;j<n;j++)
          {
            TreeNode * x=pq.front();
            int flag=0;
            if(x->left)
            {
                flag+=x->left->val;
            }
            if(x->right)
            {
                flag+=x->right->val;
            }
            if(x->left)
            {
                x->left->val=ans[i]-flag;
            }
            if(x->right)
            {
                x->right->val=ans[i]-flag;
            }
            if(x->left)
            {
                pq.push(x->left);
            }
             if(x->right)
            {
                pq.push(x->right);
            }
            pq.pop();
          }
    
        i++;
        }
        return root;

    }
};