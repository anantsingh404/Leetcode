/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    void solve(TreeNode root,int sum)
    {
        if(root.left==null && root.right==null)
        {
            ans+=sum*2+root.val;
            return;
        }
        if(root.left!=null){
        solve(root.left,sum*2+root.val);}
        if(root.right!=null){
         solve(root.right,sum*2+root.val);
         }
    }
    public int sumRootToLeaf(TreeNode root) {
        ans=0;
        solve(root,0);
        return ans;
    }
}