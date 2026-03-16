class Solution {
    public int[] getBiggestThree(int[][] grid) {
         int m = grid.length;
        int n = grid[0].length;

        TreeSet<Integer> set = new TreeSet<>(Collections.reverseOrder());

        int i = 0;
        while(i < m)
        {
            int j = 0;

            while(j < n)
            {
                set.add(grid[i][j]);

                int k = 1;

                while(true)
                {
                    if(i + 2*k >= m) break;
                    if(j - k < 0) break;
                    if(j + k >= n) break;

                    int sum = 0;

                    int r = i;
                    int c = j;

                    int step = 0;

                    while(step < k)
                    {
                        sum += grid[r][c];
                        r++;
                        c--;
                        step++;
                    }

                    step = 0;
                    while(step < k)
                    {
                        sum += grid[r][c];
                        r++;
                        c++;
                        step++;
                    }

                    step = 0;
                    while(step < k)
                    {
                        sum += grid[r][c];
                        r--;
                        c++;
                        step++;
                    }

                    step = 0;
                    while(step < k)
                    {
                        sum += grid[r][c];
                        r--;
                        c--;
                        step++;
                    }

                    set.add(sum);

                    k++;
                }

                j++;
            }

            i++;
        }

        int size = Math.min(3, set.size());

        int[] ans = new int[size];

        int idx = 0;

        for(int val : set)
        {
            ans[idx] = val;
            idx++;

            if(idx == size)
            {
                break;
            }
        }

        return ans; 
    }
}