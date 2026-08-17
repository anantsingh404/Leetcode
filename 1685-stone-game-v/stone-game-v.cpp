class Solution {
public:
int n;
int solve(int i ,int j,vector<int>&sum,vector<vector<int>>&dp)
{ 
    if(i==j || i<0 || j<0 || i>=n || j>=n || i>j) 
    { 
            return 0; 
    } 
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans=0;

    for(int k=i;k<=j;k++)
    {
       int left=sum[k];
       if(i-1>=0)
       {
          left-=sum[i-1];
       }
       int right=sum[j]-sum[k];
      
       if(left==right)
       {
        ans=max(ans,left+solve(i,k,sum,dp));
        ans=max(ans,right+solve(k+1,j,sum,dp));
       }
       else
       {
        if(left>right)
        {
            ans=max(ans,right+solve(k+1,j,sum,dp));
        }
        else
        {
            ans=max(ans,left+solve(i,k,sum,dp));
        }
       }
    }
    return dp[i][j]=ans;
}
    int stoneGameV(vector<int>& sv) {
      n=sv.size();
      vector<int>sum(n,0);
      sum[0]=sv[0];
      for(int i=1;i<n;i++)
      {
        sum[i]=sum[i-1]+sv[i];
      }
      vector<vector<int>>dp(n,vector<int>(n,-1));
      return solve(0,n-1,sum,dp);
    }
};