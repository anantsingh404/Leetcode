class Solution {
public:
int n;
int count;
void check(int idx,vector<vector<int>>&adj,vector<int>&vis,int x,int y)
{
    vis[idx]=1;
    ++count;
    for(auto itr:adj[idx])
    {
        if(((itr!=x || idx!=y) && (itr!=y || idx!=x)) && vis[itr]==0)
        {
            check(itr,adj,vis,x,y);
        }
    }

}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         n=edges.size();
     vector<vector<int>>adj(n); 
     for(int i=0;i<n;i++)
     {
        int x=edges[i][0]-1;
        int y=edges[i][1]-1;
        adj[x].push_back(y);
        adj[y].push_back(x);
     } 

    
    for(int i=n-1;i>=0;i--)
    {   vector<int>vis(n,0);
        int x=edges[i][0]-1;
        int y=edges[i][1]-1;
        count=0;
        check(0,adj,vis,x,y);
        if(count==n)
        {
            return {x+1,y+1};
        }
    }
    return {};
    }
};