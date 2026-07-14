class Solution {
public:
int mod=1e9+7;
  vector<vector<vector<int>>>dp;
int n;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int solve(int idx,vector<int>&nums,int g1,int g2)
{
    if(idx==n)
    {
        if(g1!=0 && g2!=0 && g1==g2)
        {
            return 1;
        }
        return 0;
    }
    if(dp[idx][g1][g2]!=-1)
    {
        return dp[idx][g1][g2]%mod;
    }
    int ans=0;
    if(g1==0)
    {
        ans=(ans%mod+solve(idx+1,nums,nums[idx],g2)%mod)%mod;
    }
    else
    {
         ans=(ans%mod+solve(idx+1,nums,gcd(g1,nums[idx]),g2)%mod)%mod;
    }
    if(g2==0)
    {
         ans=(ans%mod+solve(idx+1,nums,g1,nums[idx])%mod)%mod;
    }
    else
    {
         ans=(ans%mod+solve(idx+1,nums,g1,gcd(g2,nums[idx]))%mod)%mod;
    }
     ans=(ans%mod+solve(idx+1,nums,g1,g2)%mod)%mod;
    return dp[idx][g1][g2]=ans;
    
}

    int subsequencePairCount(vector<int>& nums) {
       n=nums.size();
        dp.assign(n,vector<vector<int>>(201,vector<int>(201,-1)));
        return solve(0,nums,0,0)%mod;
      
        
        
    }
};