#define  ll long long 
class Solution {
public:

    int minCost(int n, vector<vector<int>>& edges) {
      vector<vector<pair<ll,ll>>>adj(n);
      for(int i=0;i<edges.size();i++)
      {
        int x=edges[i][0];
        int y=edges[i][1];
        int w=edges[i][2];
        adj[x].push_back({y,w});
        adj[y].push_back({x,2*w});
      }
      priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
      vector<ll>dis(n,INT_MAX);
      dis[0]=0;
      pq.push({0,0});
      while(!pq.empty())
      {
        auto [x,y]=pq.top();
        pq.pop();
        if(x!=dis[y])
        {
            continue;
        }
        for(auto [p,q]:adj[y])
        {
            if(dis[p]>q+x)
            {
                pq.push({q+x,p});
                dis[p]=q+x;
            }
        }
      }
      if(dis[n-1]==INT_MAX)
      {
        return -1;
      }
      return dis[n-1];
    }
};