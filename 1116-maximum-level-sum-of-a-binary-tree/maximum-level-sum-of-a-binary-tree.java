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
    public int maxLevelSum(TreeNode root) {
      Queue<TreeNode> s = new LinkedList<>();
      s.add(root);
      int level=1;
      int bl=1;
      int ans=root.val;
      while(s.size()>0)
      {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=s.peek().val;
            if(s.peek().left!=null)
            {
                s.add(s.peek().left);
            }
            if(s.peek().right!=null)
            {
                s.add(s.peek().right);
            }
            s.remove();
        }
        if(sum>ans)
        {
            bl=level;
            ans=sum;
        }
        ++level;
      }
  return bl;
    }
}