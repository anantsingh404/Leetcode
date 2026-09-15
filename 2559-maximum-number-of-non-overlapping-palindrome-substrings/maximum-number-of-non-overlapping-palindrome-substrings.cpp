class Solution {
public:
int n;
int k;
int solve(int idx,vector<vector<int>>&ispal,vector<int>&dp)
{
    if(idx>=n || n-idx<k)
    {
        return 0;
    }
    if(dp[idx]!=-1)
    {
        return dp[idx];
    }
    int ans=0;
    ans=max(ans,solve(idx+1,ispal,dp));
    for(int j=idx+k-1;j<n;j++)
    {
        if(ispal[idx][j]==1)
        {
            ans=max(ans,1+solve(j+1,ispal,dp));
        }
    }
    return dp[idx]=ans;
}
    int maxPalindromes(string s, int kk) {
        n=s.size();
        k=kk;
      vector<vector<int>>ispal(n,vector<int>(n,-1));
      for(int i=0;i<n;i++)
      {
        int j=i-1;
        int k=i+1;
        ispal[i][i]=1;
        while(j>=0 && k<n && s[j]==s[k])
        {   if(j<k && j>=0 && k<n)
           {
            ispal[j][k]=1;
            }
            --j;
            ++k;
        }
      
      }
      for(int i=0;i<n;i++)
      {
        int j=i;
        int k=i+1;
        while(j>=0 && k<n && s[j]==s[k])
        {   if(j<k && j>=0 && k<n)
        {
            ispal[j][k]=1;
        }
            --j;
            ++k;
        }
      
      }
      vector<int>dp(n,-1);
      return solve(0,ispal,dp);

    }
};