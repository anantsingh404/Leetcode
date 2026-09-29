import java.util.Arrays;

class Solution {
    int n;
    int m;

    int solve(int i, int j, int sum, char[][] grid, int[][][] dp) {
        // 1. Out of bounds check
        if (i >= n || j >= m) {
            return 0;
        }

        // 2. Base Case: Reached the bottom-right destination
        if (i == n - 1 && j == m - 1) {
            if (sum == 1 && grid[i][j] == ')') {
                return 1;
            }
            return 0;
        }

        // 3. Return memoized result if already calculated
        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }

        // 4. Handle paths based on parentheses type
        if (grid[i][j] == ')') {
            if (sum <= 0) {
                return dp[i][j][sum] = 0; // Invalid path (more ')' than '(')
            } else {
                int down = solve(i + 1, j, sum - 1, grid, dp);
                int right = solve(i, j + 1, sum - 1, grid, dp);
                return dp[i][j][sum] = (down | right);
            }
        } else {
            int down = solve(i + 1, j, sum + 1, grid, dp);
            int right = solve(i, j + 1, sum + 1, grid, dp);
            return dp[i][j][sum] = (down | right);
        }
    }

    public boolean hasValidPath(char[][] grid) {
        n = grid.length;
        m = grid[0].length;

        // Early Pruning: An odd path length can never be balanced
        if ((n + m - 1) % 2 != 0) {
            return false;
        }
        // Early Pruning: Must start with '(' and end with ')'
        if (grid[0][0] == ')' || grid[n - 1][m - 1] == '(') {
            return false;
        }

        // Dynamically size the third dimension to exactly what's needed
        int maxSum = n + m ; 
        int[][][] dp = new int[n][m][maxSum];
        
        // Fast array initialization
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(0, 0, 0, grid, dp) == 1;
    }
}
