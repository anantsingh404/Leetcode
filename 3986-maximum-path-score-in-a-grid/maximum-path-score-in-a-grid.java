class Solution {
    int n, m;

    int solve(int i, int j, int k, int[][] grid, int[][][] dp)
    {
        // Invalid if k < 0
        if (k < 0)
        {
            return Integer.MIN_VALUE;
        }

        // Destination
        if (i == n - 1 && j == m - 1)
        {
            return 0;
        }

        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        int ans = Integer.MIN_VALUE;

        // Move Down
        if (i + 1 < n)
        {
            int val = grid[i + 1][j];

            if (val == 0)
            {
                int temp = solve(i + 1, j, k, grid, dp);
                ans = Math.max(ans, temp);
            }
            else
            {
                int temp = solve(i + 1, j, k - 1, grid, dp);
                if (temp != Integer.MIN_VALUE)
                {
                    ans = Math.max(ans, val + temp);
                }
            }
        }

        // Move Right
        if (j + 1 < m)
        {
            int val = grid[i][j + 1];

            if (val == 0)
            {
                int temp = solve(i, j + 1, k, grid, dp);
                ans = Math.max(ans, temp);
            }
            else
            {
                int temp = solve(i, j + 1, k - 1, grid, dp);
                if (temp != Integer.MIN_VALUE)
                {
                    ans = Math.max(ans, val + temp);
                }
            }
        }

        return dp[i][j][k] = ans;
    }

    public int maxPathScore(int[][] grid, int k)
    {
        n = grid.length;
        m = grid[0].length;

        // Limit k to reasonable bound
        int maxK = Math.min(k, n + m);

        int[][][] dp = new int[n][m][maxK + 1];

        // Initialize DP
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int l = 0; l <= maxK; l++)
                {
                    dp[i][j][l] = -1;
                }
            }
        }

        int res = solve(0, 0, maxK, grid, dp);

        if (res == Integer.MIN_VALUE)
        {
            return -1;
        }

        return res;
    }
}