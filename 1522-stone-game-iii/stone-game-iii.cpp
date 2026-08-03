class Solution {
public:
int n;
int solve(int idx,vector<int>&s,vector<int>&dp)
{
    if(idx>=n)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=INT_MIN;
    ans=max(ans,s[idx]-solve(idx+1,s,dp));
    if(idx+1<n){
     ans=max(ans,s[idx]+s[idx+1]-solve(idx+2,s,dp));
    }
     if(idx+2<n){
     ans=max(ans,s[idx]+s[idx+1]+s[idx+2]-solve(idx+3,s,dp));
    }
    return dp[idx]=ans;
    


}    string stoneGameIII(vector<int>& s) {
     n=s.size();   
     vector<int>dp(n,-1);
     int x=solve(0,s,dp);
     if(x>0)
     {
        return "Alice";
     }
      if(x<0)
     {
        return "Bob";
     }
     return "Tie";
    }
};