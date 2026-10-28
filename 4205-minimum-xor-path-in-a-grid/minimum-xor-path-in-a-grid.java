class Solution {
    int n;
    int m;
    int solve(int i,int j,int exor,int grid[][],int dp[][][])
    {
        if(i==n-1 && j==m-1){
            return exor^grid[i][j];
        }
        if(dp[i][j][exor]!=Integer.MAX_VALUE)
        {
            return dp[i][j][exor];
        }
        int bottomove=Integer.MAX_VALUE;
        int rightmove=Integer.MAX_VALUE;
        if(i+1<n)
        {
        bottomove=solve(i+1,j,exor^grid[i][j],grid,dp);
        }
        if(j+1<m)
        {
        rightmove=solve(i,j+1,exor^grid[i][j],grid,dp);
        }
        return dp[i][j][exor]=Math.min(bottomove,rightmove);

    }
    public int minCost(int[][] grid) {
      n=grid.length;
      m=grid[0].length;
       int dp[][][]=new int[n][m][1024];
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {  for(int k=0;k<1024;k++)
        {
            dp[i][j][k]=Integer.MAX_VALUE;
        }
        }
       }
       return solve(0,0,0,grid,dp);
    }
}