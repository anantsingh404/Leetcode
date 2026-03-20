import java.util.*;

class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int[m - k + 1][n - k + 1];

        int i = 0;
        while (i <= m - k) {
            int j = 0;
            while (j <= n - k) {

                Set<Integer> set = new HashSet<>();

                int x = i;
                while (x < i + k) {
                    int y = j;
                    while (y < j + k) {
                        set.add(grid[x][y]);   // DISTINCT
                        y++;
                    }
                    x++;
                }

                // If only 1 distinct element
                if (set.size() <= 1) {
                    dp[i][j] = 0;
                    j++;
                    continue;
                }

                List<Integer> list = new ArrayList<>(set);
                Collections.sort(list);

                int minDiff = Integer.MAX_VALUE;

                int idx = 1;
                while (idx < list.size()) {
                    int diff = list.get(idx) - list.get(idx - 1);
                    if (diff < minDiff) {
                        minDiff = diff;
                    }
                    idx++;
                }

                dp[i][j] = minDiff;

                j++;
            }
            i++;
        }

        return dp;
    }
}