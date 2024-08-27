class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],suc[i]});
            adj[edges[i][1]].push_back({edges[i][0],suc[i]});
        }
        vector<double>dp(n,INT_MIN);
        dp[start]=1;
        queue<pair<int,double>>q;
        q.push({start,1});
        while(!q.empty())
        {
            pair<int,double>x=q.front();
            q.pop();
            for(auto itr:adj[x.first])
            {
               if(dp[itr.first]<x.second*itr.second)
               {
                dp[itr.first]=x.second*itr.second;
                q.push({itr.first,dp[itr.first]});
               }   
            }
        }
        if(dp[end]>INT_MIN)
        {
            return dp[end];
        }
        return 0.0;


    }
};