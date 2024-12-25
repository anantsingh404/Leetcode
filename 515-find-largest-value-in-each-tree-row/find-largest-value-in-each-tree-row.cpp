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
    vector<int> largestValues(TreeNode* root) {
      vector<int>ans;
      queue<TreeNode *>q;
      q.push(root);
      if(!root)
      {
        return {};
      }
      while(!q.empty())
      {
        int n=q.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            TreeNode * x=q.front();
            pq.push(x->val);
            if(x->left)
            {
                q.push(x->left);
            }
             if(x->right)
            {
                q.push(x->right);
            }
            q.pop();
        }
        if(pq.size()>0){
        ans.push_back(pq.top());
        }
      } 
      return ans; 
    }
};