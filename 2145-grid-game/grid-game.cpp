class Solution {
public:
int n;
long long solve(int i,int j,vector<vector<long long>>&dp,vector<vector<int>>&grid)
{   
    if(i==1 && j==n-1)
{
    return grid[i][j];
}
    if(i>1)
    {
        return -1e6;
    }
    if(j>=n)
    {
        return -1e6;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long ans=0;
    ans+=grid[i][j]+solve(i+1,j,dp,grid);
    
     
    
      ans=max(ans,grid[i][j]+solve(i,j+1,dp,grid));
      return dp[i][j]=ans;
    
}
    long long gridGame(vector<vector<int>>& grid) {
        n=grid[0].size();
    vector<vector<long long>>dp(2,vector<long long>(n,-1));  
    long long s1=accumulate(grid[0].begin(),grid[0].end(),1ll*0);
    long long s2=accumulate(grid[1].begin(),grid[1].end(),1ll*0);
    long long x=solve(0,0,dp,grid);
    vector<long long>left(n,0);
    vector<long long>right(n,0);
    left[0]=grid[0][0];
    for(int i=1;i<n;i++)
    {

         left[i]=left[i-1]+ grid[0][i];
    }
    right[n-1]=grid[1][n-1];
    for(int i=n-2;i>=0;i--)
    {

         right[i]=right[i+1]+grid[1][i];
    }
   
   
    long long ans=1e18;
    for(int i=0;i<n;i++)
    {
       long long a=s1-left[i];
       long long b=s2-right[i];
       long long flag=max(a,b);
       ans=min(ans,flag);
    }
    return ans;
    



    }
};