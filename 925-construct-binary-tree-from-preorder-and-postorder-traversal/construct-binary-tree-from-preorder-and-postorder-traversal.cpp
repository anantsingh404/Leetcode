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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      int preIdx = 0, postIdx = 0;
        stack<TreeNode*> nodes;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        nodes.push(root);

        while(!nodes.empty()) {
            TreeNode* cur = nodes.top();
            if(cur->val == postorder[postIdx]) {
                nodes.pop();
                postIdx++;
            } else {
                TreeNode* child = new TreeNode(preorder[preIdx++]);
                if(cur->left != NULL) {
                    cur->right = child;
                } else {
                    cur->left = child;
                }
                nodes.push(child);
            }
        }
        return root;   
    }
};