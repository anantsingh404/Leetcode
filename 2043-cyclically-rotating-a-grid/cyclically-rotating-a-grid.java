class Solution {
    public int[][] rotateGrid(int[][] grid, int k) 
    {
        int n = grid.length;
        int m = grid[0].length;

        int i = 0;
        int ii = n - 1;
        int j = 0;
        int jj = m - 1;

        while (i < ii && j < jj)
        {
            ArrayList<Integer> ls = new ArrayList<>();

            // top row
            int col = j;
            while (col <= jj)
            {
                ls.add(grid[i][col]);
                col++;
            }

            // right column
            int row = i + 1;
            while (row <= ii)
            {
                ls.add(grid[row][jj]);
                row++;
            }

            // bottom row
            col = jj - 1;
            while (col >= j)
            {
                ls.add(grid[ii][col]);
                col--;
            }

            // left column
            row = ii - 1;
            while (row > i)
            {
                ls.add(grid[row][j]);
                row--;
            }

            int sz = ls.size();
            int rot = k % sz;

            ArrayList<Integer> temp = new ArrayList<>();

            int idx = rot;
            while (idx < sz)
            {
                temp.add(ls.get(idx));
                idx++;
            }

            idx = 0;
            while (idx < rot)
            {
                temp.add(ls.get(idx));
                idx++;
            }

            int p = 0;

            // top row
            col = j;
            while (col <= jj)
            {
                grid[i][col] = temp.get(p++);
                col++;
            }

            // right column
            row = i + 1;
            while (row <= ii)
            {
                grid[row][jj] = temp.get(p++);
                row++;
            }

            // bottom row
            col = jj - 1;
            while (col >= j)
            {
                grid[ii][col] = temp.get(p++);
                col--;
            }

            // left column
            row = ii - 1;
            while (row > i)
            {
                grid[row][j] = temp.get(p++);
                row--;
            }

            i++;
            ii--;
            j++;
            jj--;
        }

        return grid;
    }
}