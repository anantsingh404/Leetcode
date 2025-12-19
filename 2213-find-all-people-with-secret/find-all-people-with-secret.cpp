class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int fp) {
       vector<pair<int,int>>adj[n];
       for(int i=0;i<meet.size();i++)
       {
           adj[meet[i][0]].push_back({meet[i][1],meet[i][2]});
           adj[meet[i][1]].push_back({meet[i][0],meet[i][2]});
       } 
       vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>ans;
    ans.push_back(0);
    pq.push({0,0});
    pq.push({0,fp});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int time=p.first;
        int node=p.second;
        if(vis[node])
        {
            continue;
        }
        vis[node]=1;
        
        for(auto itr:adj[node])
        {
            int dst=itr.first;
            int rt=itr.second;
            if(vis[dst])
            {
                continue;
            }
            if(rt>=time)
            {
                pq.push({rt,dst});
            }


        }
    }
     for(int i=1;i<n;i++)
     {
         if(vis[i])
         {
             ans.push_back(i);
         }
     }
       return ans;
    }
};