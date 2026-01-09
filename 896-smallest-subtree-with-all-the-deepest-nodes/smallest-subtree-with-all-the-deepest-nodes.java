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
   TreeNode x=null;
   public boolean solve1(TreeNode root,int depth,int cd){
    if(root==null && cd==depth+1)
    {
        return true;
    }
     if(root==null)
    {
        return false;
    }
    boolean xx=solve1(root.left,depth,cd+1);
    boolean yy=solve1(root.right,depth,cd+1);
    if(xx==true && yy==true)
    {
        x=root;
    }
    boolean ans=false;
    if(cd==depth)
    {
        ans=true;
    }
   
   ans=ans|xx;
   ans=ans|yy;
   return ans;
}

    int solve(TreeNode root)
    {
        if(root==null)
        {
            return 0;
        }
        return 1+Math.max(solve(root.left),solve(root.right));
    }
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
      int depth=solve(root);
      System.out.println(depth);
      
      solve1(root,depth,1);
      return x;  
    }
}