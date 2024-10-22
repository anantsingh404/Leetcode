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
    long long kthLargestLevelSum(TreeNode* root, int k) {
       queue<TreeNode *>stackk;
         priority_queue<long, vector<long>, greater<long>> st;
      // st.insert(root->val);
       stackk.push(root);
       while(!stackk.empty())
       {
        int n=stackk.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=stackk.front()->val;
            TreeNode *x=stackk.front();
             stackk.pop();
            if(x->left)
            {
                stackk.push(x->left);
            } 
              if(x->right)
            {
                stackk.push(x->right);
            } 
           

        }
        st.push(sum);
       }

    if(st.size()<k)
    {
        return -1;
    }
    while(st.size()>k)
    {
        st.pop();
    }
    return st.top();

    }
};