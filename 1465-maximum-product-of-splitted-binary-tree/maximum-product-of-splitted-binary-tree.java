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
      long totalSum = 0;
    long maxProduct = 0;
    int mod = 1000000007;

    long dfs(TreeNode root) {
        if (root == null) return 0;

        long left = dfs(root.left);
        long right = dfs(root.right);

        long subSum = root.val + left + right;

        maxProduct = Math.max(
            maxProduct,
            subSum * (totalSum - subSum)
        );

        return subSum;
    }

    long getSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getSum(root.left) + getSum(root.right);
    }

    public int maxProduct(TreeNode root) {
        totalSum = getSum(root);
        dfs(root);
        return (int)(maxProduct % mod);
    }
}