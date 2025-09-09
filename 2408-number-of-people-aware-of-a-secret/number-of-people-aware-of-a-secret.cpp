class Solution {
public:
const int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
     long long sum=0;
     vector<int>dp(n+1,0);
     dp[1]=1;
     for(int i=2;i<=n;i++)
     {
        long long fr=0;
        if(i-forget>=1)
        {
            fr=dp[i-forget];
        }
        long long nl=0;
        if(i-delay>=1)
        {
            nl=dp[i-delay];
        }
        sum=(sum+nl-fr+mod)%mod;
        dp[i]=sum;


     }
     long ans=0;
        for(int i=n-forget+1; i<=n; i++){
            ans = (ans+dp[i])%mod;
        }
        return ((int)ans);
     
    }
};