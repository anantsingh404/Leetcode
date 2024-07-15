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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
      unordered_map<int,TreeNode *>mp;
      unordered_map<int,int>child;
      for(int i=0;i<desc.size();i++) 
      {
        if(desc[i][2])
        {   TreeNode *x;
            if(mp.find(desc[i][0])!=mp.end())
            {
             x=mp[desc[i][0]];
            }
            else{
             x=new TreeNode(desc[i][0]);
             mp[desc[i][0]]=x;
            }
             TreeNode *y;
             if(mp.find(desc[i][1])!=mp.end()){
                y=mp[desc[i][1]];
             }
             else
             {
             y=new TreeNode(desc[i][1]);
             mp[desc[i][1]]=y;
             }
             x->left=y;
             
             child[desc[i][1]]++;
            }
           
        
        else
        {
          
              TreeNode *x;
            if(mp.find(desc[i][0])!=mp.end())
            {
             x=mp[desc[i][0]];
            }
            else
            {
             x=new TreeNode(desc[i][0]);
              mp[desc[i][0]]=x;
            }
             TreeNode *y;
             if(mp.find(desc[i][1])!=mp.end()){
                y=mp[desc[i][1]];
             }
             else
             {
             y=new TreeNode(desc[i][1]);
             mp[desc[i][1]]=y;
             }
             x->right=y;
             
             child[desc[i][1]]++;
            }
            
        }
        for(auto itr:mp)
        {
            if(child.find(itr.first)==child.end())
            {
                return itr.second;
            }
        }
      
      return 0;
    }
};