class Solution {
public:
long long mod=1e9+7;
long long power(long long base,long long expo)
{
    if(expo==0)
    {
        return 1;
    }
    
    long long x=power(base,expo/2);
    if(expo%2)
    {
        return x*x*base;
    }
    return x*x;

}
  long long   solve(long long n,long long c,vector<vector<long long>>&dp,long long x)
    {
        if (n == 0) return 1;
    if (c < 0) return 0; 
    if (dp[n][c] != -1) return dp[n][c];
    
    long long ans = 0;
    for (long long i = c; i >= 1; i--) 
    {
        long long p = power(i, x);
        if (p <= n)
        {
            ans =(ans%mod+ solve(n - p, i - 1, dp, x)%mod)%mod;
        }
        
    }
    return dp[n][c] = ans%mod;
    }
    int numberOfWays(int n, int x) 
    {
        
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        
        return (int)solve(1ll*n,1ll*n,dp,1ll*x);


    }
};