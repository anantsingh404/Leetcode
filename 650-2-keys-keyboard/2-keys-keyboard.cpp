class Solution {
public:
long long solve(long long n,vector<vector<long long>>&dp,long long sum,long long cur)
{   if(sum==n)
    {
    return 0;
    }
    if(sum>n || cur>n)
    {
        return 1e9+7;
    }
    if(dp[sum][cur]!=-1)
    {
        return dp[sum][cur];
    }
    long long ans=1e9+7;
    if(sum*2<=n)
    {
        ans=min(ans,2+solve(n,dp,sum*2,sum));
    }
     if(cur+sum<=n)
    {
        ans=min(ans,1+solve(n,dp,sum+cur,cur));
    }
    return dp[sum][cur]=ans;
}
    int minSteps(long long int n) {
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        if(n==1)
        {
            return 0;
        }
        return 1+solve(n,dp,1,1);
    }
};