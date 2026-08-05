class Solution {
public:
void dfs(int idx,set<int>&st,vector<int>adj[],bool &res,vector<int>&vis)
{  vis[idx]=1;
   for(auto itr:adj[idx])
   {
      if(st.find(itr)!=st.end())
      { res=false;
       
      }
      if(vis[itr]==0){
       dfs(itr,st,adj,res,vis);
      }
   } 
}
void solve(int idx,vector<int>adj[],set<int>&ans,vector<int>&vis)
{
    ans.insert(idx);
    vis[idx]=1;
    for(auto itr:adj[idx])
    {
        if(vis[itr]==0)
        {
            solve(itr,adj,ans,vis);
        }
    }
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invo) {
     vector<int>vis(n,0);
     vector<int>adj[n];
     for(int i=0;i<invo.size();i++)
     {
        adj[invo[i][0]].push_back(invo[i][1]);
     } 
     set<int>ans;
      solve(k,adj,ans,vis);
      bool res =true;
     for(int i=0;i<n;i++)
     {
        if(vis[i]==0)
        {
            dfs(i,ans,adj,res,vis);
        }
     }
     if(res)
     {
        vector<int>anss;
      for(int i=0;i<n;i++)
      {
        if(ans.find(i)==ans.end()){
            anss.push_back(i);
        }
      }
        return anss;
     }
     vector<int>tmp;
     for(int i=0;i<n;i++)
     {
        tmp.push_back(i);
     }
     return tmp;

    }
};