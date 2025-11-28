class Solution {
public:
vector<int>val;
vector<vector<int>>adj;
int kk;
int count=0;

int solve(int idx,int parent)
{    int temp=val[idx]%kk;
    for(auto itr:adj[idx])
    {
        if(itr!=parent)
        {
            int x=solve(itr,idx);
            
            temp+=x;
        }
    }
    if(temp%kk==0)
    {
        ++count;
    }
   
    return temp%kk;

}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
    val.resize(n);
        val.assign(values.begin(),values.end());
        adj.resize(n);
        kk=k;
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        solve(0,-1);
        return count;
    }
};