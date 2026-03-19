class Solution {
    public int numberOfSubmatrices(char[][] grid) {
      int ans=0;
     int n=grid.length;
     int m=grid[0].length;
     int [][] dp1=new int[n][m];
     int [][] dp2=new int[n][m];
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            dp1[i][j]=0;
            dp2[i][j]=0;
        }
     }
     for(int j=0;j<m;j++)
     {
        if(grid[0][j]=='X')
        {
            dp1[0][j]=1;
        }
     }
     for(int j=0;j<m;j++)
     {
        if(grid[0][j]=='Y')
        {
            dp2[0][j]=1;
        }
     }
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(grid[i][j]=='X')
            {
                dp1[i][j]=dp1[i-1][j]+1;
            }
            else
            {
                dp1[i][j]=dp1[i-1][j];
            }
            if(grid[i][j]=='Y')
            {
                dp2[i][j]=dp2[i-1][j]+1;
            }
            else
            {
                dp2[i][j]=dp2[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {   int sum1=0;
        int sum2=0;
        for(int j=0;j<m;j++)
        {
            sum1+=dp1[i][j];
            sum2+=dp2[i][j];
            if(sum1>0 && sum1==sum2)
            {
                ++ans;
            }
        }
    } 
    return ans;    
    }
}