class Solution {
    int n;
    int m;
    int solve(int i,int j,int sum,char [][]grid,int [][][]dp){
        if(i>=n || j>=m)
        {
            return 0;
        }
        if(i==n-1 && j==m-1 && sum==1 && grid[i][j]==')')
        {
            return 1;
        }
        if(dp[i][j][sum]!=-1)
        {
            return dp[i][j][sum];
        }
        if(grid[i][j]==')')
        {
            if(sum<=0)
            {
                return dp[i][j][sum]=0;
            }
            else
            {
            dp[i][j][sum]=solve(i+1,j,sum-1,grid,dp);
            dp[i][j][sum]=dp[i][j][sum]|solve(i,j+1,sum-1,grid,dp);
            }
        }
        else
        {
           dp[i][j][sum]=solve(i+1,j,sum+1,grid,dp);
            dp[i][j][sum]=dp[i][j][sum]|solve(i,j+1,sum+1,grid,dp);   
        }
        return dp[i][j][sum];

    }
    public boolean hasValidPath(char[][] grid) {
       n=grid.length;
       m=grid[0].length;
       int dp[][][]=new int[201][201][201];
       for(int i=0;i<201;i++)
       {
              for(int j=0;j<201;j++)
              {
                 for(int k=0;k<201;k++)
                 {
                    dp[i][j][k]=-1;
                 }
              }
       } 
       int x=solve(0,0,0,grid,dp);
       if(x==1)
       {
        return true;
       }
       return false;
    }

}