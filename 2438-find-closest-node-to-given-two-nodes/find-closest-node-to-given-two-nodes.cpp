class Solution {
public:
void solve(int idx,vector<vector<int>>&adj,unordered_map<int,int>&mp,vector<int>&vis,int dis)
{
    vis[idx]=1;
    mp[idx]=dis;
    for(auto itr:adj[idx])
    {
        if(vis[itr]==0)
        {
            solve(itr,adj,mp,vis,dis+1);
        }
    }

}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
     int n=edges.size();
     vector<vector<int>>adj(n);
     for(int i=0;i<n;i++)
     { 
        if(edges[i]!=-1)
        {
        adj[i].push_back(edges[i]);
        }
     } 
     unordered_map<int,int>mp1,mp2;
     vector<int>vis(n,0);
     solve(node1,adj,mp1,vis,1);
     vis.assign(n,0);
     solve(node2,adj,mp2,vis,1);
     int idx=INT_MAX;
     int res=INT_MAX;
    for (auto& [node, d1] : mp1) {
    if (mp2.count(node)) {
        int d2 = mp2[node];
        int maxDis = max(d1, d2);
        if (maxDis < res || (maxDis == res && node < idx)) {
            res = maxDis;
            idx = node;
        }
    }
}
     if(res==INT_MAX)
     {
        return -1;
     }
     return idx;
    }
};