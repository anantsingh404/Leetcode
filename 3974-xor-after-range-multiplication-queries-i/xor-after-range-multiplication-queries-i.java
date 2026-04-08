class Solution {
    public int xorAfterQueries(int[] nums, int[][] q) {
        final int mod = 1000000007;
        int n = nums.length;

        for(int i = 0; i < q.length; i++)
        {
            int x = q[i][0];
            int y = q[i][1];
            int k = q[i][2];
            int v = q[i][3];

            for(int j = x; j <= y; j += k)
            {
                nums[j] = (int)(((long)nums[j] * v) % mod);
            }
        }

        int xor = 0;
        for(int i = 0; i < n; i++)
        {
            xor ^= nums[i];
        }

        return xor;
    }
}