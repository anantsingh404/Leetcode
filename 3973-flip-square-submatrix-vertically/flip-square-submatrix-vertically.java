class Solution {
    public int[][] reverseSubmatrix(int[][] grid, int x, int y, int k) {
      int n=grid.length;
      int m=grid[0].length;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
            if(i==x && j==y)
            {
                int low=j;
                int high=j+k-1;
                while(low<=high)
                {
                    int h=i+k-1;
                    int g=i;
                    while(g<=h)
                    {
                        int xx=grid[g][low];
                        int yy=grid[h][low];
                        grid[g][low]=yy;
                        grid[h][low]=xx;
                        g++;
                        h--;
                    }
                    ++low;
                }

            }
        }
      }
    return grid;
    }
}