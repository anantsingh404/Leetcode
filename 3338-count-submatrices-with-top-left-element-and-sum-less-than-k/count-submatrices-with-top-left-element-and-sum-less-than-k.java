class Solution {
    public int countSubmatrices(int[][] grid, int k) {
     int ans=0;
     int n=grid.length;
     int m=grid[0].length;
     for(int i=1;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            grid[i][j]=grid[i-1][j]+grid[i][j];
        }
     } 
      for(int i=0;i<n;i++)
     {  int sum=0;
        for(int j=0;j<m;j++)
        {
            sum+=grid[i][j];
            if(sum<=k)
            {
                ++ans;
            }
        }
     }
     return ans;   
    }
}