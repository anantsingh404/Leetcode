class Solution {
    public boolean canPartitionGrid(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        long total = 0;

        int i, j;

        // total sum
        i = 0;
        while(i < n)
        {
            j = 0;
            while(j < m)
            {
                total += grid[i][j];
                j++;
            }
            i++;
        }

        if(total % 2 != 0)
        {
            return false;
        }

        long target = total / 2;

        // 🔥 row cut
        long sum = 0;
        i = 0;
        while(i < n - 1)
        {
            j = 0;
            while(j < m)
            {
                sum += grid[i][j];
                j++;
            }

            if(sum == target)
            {
                return true;
            }

            i++;
        }

        // 🔥 column cut
        sum = 0;
        j = 0;
        while(j < m - 1)
        {
            i = 0;
            while(i < n)
            {
                sum += grid[i][j];
                i++;
            }

            if(sum == target)
            {
                return true;
            }

            j++;
        }

        return false;
    }
}