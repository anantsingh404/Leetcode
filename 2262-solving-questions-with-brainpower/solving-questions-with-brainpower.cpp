class Solution {
public:
int n;
long long solve(int idx,vector<vector<int>>&q,vector<long long>&dp)
{
    if(idx>=n)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    long long ans=INT_MIN;
    ans=max(ans,q[idx][0]+solve(idx+q[idx][1]+1,q,dp));
    ans=max(ans,solve(idx+1,q,dp));
    return dp[idx]=ans;
}
    long long mostPoints(vector<vector<int>>& q)
    {
       n=q.size();
       vector<long long>dp(n,-1);
       return solve(0,q,dp);

    }
};