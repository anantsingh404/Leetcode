class Solution {
public:
int n;
int p,q;
int solve(int idx,int sumo,int sumz,vector<pair<int,int>>&vp,vector<vector<vector<int>>>&dp)
{
    if(idx>=n && sumo<=p && sumz<=q)
    {
        return 0;
    }
    if(idx>=n)
    {
        return -1e6;
    }
    if(dp[idx][sumo][sumz]!=-1)
    {
        return dp[idx][sumo][sumz];
    }
    int ans=-1e6;
    if(sumo+vp[idx].first<=p && sumz+vp[idx].second<=q)
    {
        ans=1+solve(idx+1,sumo+vp[idx].first,sumz+vp[idx].second,vp,dp);
    }
     ans=max(ans,solve(idx+1,sumo,sumz,vp,dp));
     return dp[idx][sumo][sumz]=ans;
}
    int findMaxForm(vector<string>& s, int zero, int one) {
       vector<pair<int,int>>vp;
       n=s.size();
       p=one;
       q=zero;
       for(int i=0;i<s.size();i++)
       { 
        int o=0,z=0;
        for(int j=0;j<s[i].size();j++)
        {
          o+=s[i][j]-'0';
          if(s[i][j]=='0')
          {
            ++z;
          }
        }
        vp.push_back({o,z});
       }
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(101,vector<int>(101,-1)));
       return solve(0,0,0,vp,dp);

    }
};