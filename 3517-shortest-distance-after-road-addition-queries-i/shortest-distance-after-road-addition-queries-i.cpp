class Solution {
public:
int solve(vector<int>adj[],int idx,int n)
{   
    //int n=adj.size();
   vector<int>dp(n,INT_MAX);
   dp[0]=0;
   queue<int>q;
   q.push(0);
   while(!q.empty())
   {
    int x=q.front();
    q.pop();
    for(auto itr:adj[x])
    {
      if(dp[itr]>dp[x]+1)
      {
        dp[itr]=dp[x]+1;
        q.push(itr);
      }
    }
   }
   return dp[n-1];

}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       vector<int>adj[n];
       for(int i=0;i<n-1;i++)
       {
       // adj[i+1].push_back(i);
        adj[i].push_back(i+1);
       }
       vector<int>ans;
       for(auto itr:queries)
       {
        adj[itr[0]].push_back(itr[1]);
        //adj[itr[1]].push_back(itr[0]);
        int x=solve(adj,0,n);
        ans.push_back(x);
       }
       return ans;

    }
};