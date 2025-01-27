class Solution {
public:
bool solve(int x,int y, vector<vector<int>>&dp,vector<int>&vis)
{  if(x==y)
  {
    return true;
  }
  vis[x]=1;
   bool ans=false;
   for(int itr:dp[x])
   {  if(itr!=x && vis[itr]==0){
    
      ans=ans|solve(itr,y,dp,vis);
   }
   }
   return ans;

}
    vector<bool> checkIfPrerequisite(int nc, vector<vector<int>>& pr, vector<vector<int>>&  q)  {
     vector<vector<int>>dp(nc);
     for(int i=0;i<pr.size();i++)
     {
        int x=pr[i][0];
        int y=pr[i][1];
        dp[x].push_back(y);
     }
     vector<bool>ans;
     for(int i=0;i<q.size();i++)
     {
        int x=q[i][0];
        int y=q[i][1];
        vector<int>vis(nc,0);
        ans.push_back(solve(x,y,dp,vis));
     }
     return ans;
     
    }
};