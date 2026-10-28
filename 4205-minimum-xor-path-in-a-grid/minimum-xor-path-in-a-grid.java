class Solution {
    public int minCost(int[][] grid) {
           int n = grid.length;
        int m = grid[0].length;
        
        // dp[j][k] stores whether a XOR value 'k' is reachable at column 'j'
        // We only need the current row and the previous row's results (space optimization)
        boolean[][] dp = new boolean[m][1024];
        
        // Base case: starting cell
        dp[0][grid[0][0]] = true;
        
        // Fill the first row (can only come from the left)
        for (int j = 1; j < m; j++) {
            int val = grid[0][j];
            for (int k = 0; k < 1024; k++) {
                if (dp[j - 1][k]) {
                    dp[j][k ^ val] = true;
                }
            }
        }
        
        // Process the rest of the grid row by row
        for (int i = 1; i < n; i++) {
            boolean[][] nextDp = new boolean[m][1024];
            
            for (int j = 0; j < m; j++) {
                int val = grid[i][j];
                
                for (int k = 0; k < 1024; k++) {
                    // Come from the top (previous row, same column)
                    if (dp[j][k]) {
                        nextDp[j][k ^ val] = true;
                    }
                    // Come from the left (same row, previous column)
                    if (j > 0 && nextDp[j - 1][k]) {
                        nextDp[j][k ^ val] = true;
                    }
                }
            }
            dp = nextDp; // Move to the next row
        }
        
        // Find the minimum XOR value reachable at the destination cell (n-1, m-1)
        for (int k = 0; k < 1024; k++) {
            if (dp[m - 1][k]) {
                return k;
            }
        }
        
        return 0;
    }
}