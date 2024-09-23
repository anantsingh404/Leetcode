class Solution {
public:
unordered_map<string,int>mp;
vector<int>dp;
int n;
long long solve(int idx,string &s)
{
    if(idx>=n)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    long long ans=INT_MAX;
    string temp;
    for(int i=idx;i<n;i++)
    {
temp.push_back(s[i]);
if(mp[temp])
{
    ans=min(ans,1ll*solve(i+1,s));
}
ans=min(1ll*ans,1ll*(i-idx)+1+solve(i+1,s));
    }
    return dp[idx]=ans;
}
    int minExtraChar(string s, vector<string>& dict) {
       
       for(auto itr:dict)
       {
        mp[itr]++;
       }
       n=s.size();
       dp.assign(n,-1);
       return solve(0,s);
    }
};