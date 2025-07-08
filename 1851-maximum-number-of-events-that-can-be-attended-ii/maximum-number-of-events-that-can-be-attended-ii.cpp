class Solution {
public:
  int n;
  vector<int>flag;
   int solve(int idx,vector<vector<int>>&e,vector<vector<int>>&dp,int k)
   {
    if(idx>=n  || k==0)
    {
        return 0;
    }
    if(dp[idx][k]!=-1)
    {
        return dp[idx][k];
    }
    int take=0,nottake=0;
    nottake=solve(idx+1,e,dp,k);
    int itr=lower_bound(flag.begin(),flag.end(),e[idx][1]+1)-flag.begin();
    take=e[idx][2]+solve(itr,e,dp,k-1);
    return dp[idx][k]=max(nottake,take);
   }
    int maxValue(vector<vector<int>>& e, int k) {
        n=e.size();
         sort(e.begin(),e.end());
        for(int i=0;i<n;i++)
        {
            flag.push_back(e[i][0]);
        }
      
       vector<vector<int>>dp(n,vector<int>(k+1,-1));
       return solve(0,e,dp,k);
    }
};