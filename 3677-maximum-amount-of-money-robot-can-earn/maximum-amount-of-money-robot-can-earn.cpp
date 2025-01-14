class Solution {
public:
vector<vector<vector<int>>>dp;
int n,m;
int solve(int i,int j,vector<vector<int>>&grid,int kill)
{
    if(i>=n || j>=m)
    {
        return -1e7;
    }
    if(i==n-1 && j==m-1)
    {
       if(grid[i][j]<0)
       {
        if(kill<2)
        {
            return 0;
        }
        else
        {
            return grid[i][j];
        }
       }
       return grid[i][j];
    }
    if(dp[i][j][kill]!=INT_MIN)
    {
        return dp[i][j][kill];
    }
    int ans=-1e7;
    if(grid[i][j]<0)
    {
        if(kill<2)
        {
            ans=max(ans,solve(i+1,j,grid,kill+1));
            ans=max(ans,solve(i,j+1,grid,kill+1));
             ans=max(ans,grid[i][j]+solve(i+1,j,grid,kill));
            ans=max(ans,grid[i][j]+solve(i,j+1,grid,kill));

        }
        else
        {
             ans=max(ans,grid[i][j]+solve(i+1,j,grid,kill));
             ans=max(ans,grid[i][j]+solve(i,j+1,grid,kill));
        }
    }
    else
    {
        
            ans=max(ans,abs(grid[i][j])+solve(i+1,j,grid,kill));
            ans=max(ans,abs(grid[i][j])+solve(i,j+1,grid,kill));
            

       
    }
    return dp[i][j][kill]=ans;


}
    int maximumAmount(vector<vector<int>>& coins) {
      n=coins.size();
      m=coins[0].size();  
      dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
      return solve(0,0,coins,0);
    }
};