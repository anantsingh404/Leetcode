class Solution {
public:
int n;
int solve(int idx,vector<int>&days,vector<int>&costs,vector<int>&dp)
{
    if(idx>=days.size())
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=INT_MAX;
    ans=min(ans,costs[0]+solve(idx+1,days,costs,dp));
    int temp=0;
    int i=idx;
    while(i<min(n,idx+7))
    {
      if(days[i]-days[idx]>=7)
      {
        break;
      }
      i++;
    }
    ans=min(ans,costs[1]+solve(i,days,costs,dp));
    i=idx;
    while(i<min(n,idx+30))
    {
      if(days[i]-days[idx]>=30)
      {
        break;
      }
      i++;
    }
     ans=min(ans,costs[2]+solve(i,days,costs,dp));
     return dp[idx]=ans;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
      n=days.size();
      sort(days.begin(),days.end());
      vector<int>dp(n,-1);
      return solve(0,days,costs,dp);

    }
};