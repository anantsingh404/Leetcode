class Solution {
public:
int n;
const int mod=1e9+7;
    int solve(int idx,int sum,string &c,vector<vector<int>>&dp)
    {
       if(idx>=n && sum==2)
       {
        return 1;
       }
       if(idx>=n)
       {
        return 0;
       }
       if(dp[idx][sum]!=-1)
       {
        return dp[idx][sum]%mod;
       }
       int ans=0;
       if(sum==2)
       {
        if(c[idx]=='S')
        {
            ans+=solve(idx+1,1,c,dp);
        }
        else{
            ans=(ans%mod+solve(idx+1,sum,c,dp)%mod);
            ans=(ans%mod+solve(idx+1,0,c,dp)%mod)%mod;
        }
       }
       else
       {
        ans=(ans%mod+solve(idx+1,c[idx]=='S'?sum+1:sum,c,dp)%mod)%mod;
       }
       return dp[idx][sum]=ans%mod;
    }
    int numberOfWays(string c) {
      n=c.size();
      vector<vector<int>>dp(n,vector<int>(3,-1));
      return solve(0,0,c,dp);  
    }
};