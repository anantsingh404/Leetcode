class Solution {
public:
vector<bool>vis;
  vector<bool>dp;
  bool solve(int node,vector<vector<int>> &adj)
  {
      if(dp[node])
      {
          return true;
          }
      if(vis[node])
      {
          return false;
      }
      vis[node]=true;
      bool ans=true;
      
      for(auto itr:adj[node])
      {
          ans=ans&solve(itr,adj);
      }
     
      return dp[node]=ans;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vis.assign(V,false);
    dp.assign(V,false);
      for(int i=0;i<V;i++)
      {  if(!vis[i]){
          solve(i,adj);
      }
      }
      vector<int>res;
      for(int i=0;i<V;i++)
      {
          if(dp[i])
          {
              res.push_back(i);
          }
      }
      return res;
    }
};