class Solution {
public:
int n,m;
const int mod=1e9+7;
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int k,int elem)
    {
        if(i>=n ||i<0 ||j>=m || j<0 || (i==n-1 && j==m-1 && elem!=0))
        {
            return 0;
        }
        if(i==n-1 && j==m-1 && elem==0)
        {
            return 1;
        }if(dp[i][j][elem]!=-1)
        {
            return dp[i][j][elem];
        }
        int ans=0;
        if(i+1<n)
        {
             ans=(ans%mod+solve(i+1,j,grid,dp,k,(elem+grid[i+1][j])%k)%mod)%mod;
        }
        if(j+1<m)
        {
            ans=(ans%mod+solve(i,j+1,grid,dp,k,(elem+grid[i][j+1])%k)%mod)%mod;
        }
        return dp[i][j][elem]=ans%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
      n=grid.size();
      m=grid[0].size();
      vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(50,-1)));
      return solve(0,0,grid,dp,k,grid[0][0]%k);  
    }
};