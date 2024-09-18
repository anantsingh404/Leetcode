class Solution {
public:
int n,m;
long long solve(int i,int j,vector<int>&a,vector<int>&b,vector<vector<long long>>&dp)
{
    if(j==m)
    {
        return 0;
    }
    if(i==n)
    {
        return -1e18;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    long long ans=0;
    ans=1ll*a[i]*b[j]+solve(i+1,j+1,a,b,dp);
    ans=max(ans,solve(i+1,j,a,b,dp));
    return dp[i][j]=ans;
    

}
    long long maxScore(vector<int>& a, vector<int>& b) {
        m=a.size();
        n=b.size();
      vector<vector<long long>>dp(n,vector<long long>(m,-1));
      long long x=solve(0,0,b,a,dp);  
      if(x<=-1e18)
      {
        return -1;
      }
      return x;
    }
};